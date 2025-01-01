#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<pii> g[10000];
int n;
pii dfs(int now, int p) {
    int ret_node = now;
    int ret_dist = 0;
    for(auto [next, cost] : g[now]) {
        if(next == p) continue;
        auto [node, dist] = dfs(next, now);
        dist += cost;
        if(dist > ret_dist) {
            ret_node = node;
            ret_dist = dist;
        }
    }
    return {ret_node, ret_dist};
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].emplace_back(t2, t3);
        g[t2].emplace_back(t1, t3);
    }

    auto [node, dist] = dfs(1, -1);
    auto [ans_node, ans_dist] = dfs(node, -1);
    cout << ans_dist << '\n';
    return 0;
}