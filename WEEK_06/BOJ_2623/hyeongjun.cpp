#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int ind[1001];
vector<int> g[1001];
int main() {
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        int p = -1;
        for(int j = 0; j < t; j++) {
            int now; cin >> now;
            if(p != -1) {
                g[p].push_back(now);
                ind[now]++;
            }
            p = now;
        }
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(const int &next : g[now]) {
            ind[next]--;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }
    if(ans.size() != n) cout << 0 << '\n';
    else {
        for(const int &x : ans) {
            cout << x << '\n';
        }
    }
    return 0;
}
