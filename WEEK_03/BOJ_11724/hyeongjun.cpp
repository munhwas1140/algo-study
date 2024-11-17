#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[1001];
bool visited[1001];
void dfs(int now) {
    visited[now] = true;
    for(const int &next : g[now]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}
