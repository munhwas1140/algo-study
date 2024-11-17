#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[10001], gr[10001];
bool visited[10001];
int w[10001], dp[10001][2];

void dfs(int now) {
    visited[now] = true;
    for(int next : g[now]) {
        if(visited[next] == false) {
            gr[now].push_back(next);
            dfs(next);
        }
    }
}

int go(int now, int state) {
    int &ret = dp[now][state];
    if(ret != -1) {
        return ret;
    }
    ret = 0;

    for(int next : gr[now]) {
        if(state == 0) {
            ret +=  max(go(next, 0), go(next, 1) + w[next]);
        } else {
            ret += go(next, 0);
        }
    }
    return ret;
}

vector<int> ans;
void trace(int now, int state) {
    if(state == 1) ans.push_back(now);

    for(int next : gr[now]) {
        if(state == 0) {
            if(go(next, 0) < go(next, 1) + w[next]) {
                trace(next, 1);
            } else {
                trace(next, 0);
            }
        } else {
            trace(next, 0);
        }
    }
}

int main() {
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    g[0].push_back(1);
    dfs(0);

    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';

    trace(0, 0);
    sort(ans.begin(), ans.end());
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
