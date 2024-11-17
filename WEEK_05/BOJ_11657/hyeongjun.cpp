#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<pll> g[501];
ll dist[501];
constexpr ll INF = 1e13;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        g[s].emplace_back(e, t);
    }

    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 1; j <= n; j++) {
            for(auto &[next, d] : g[j]) {
                if(dist[j] != INF && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                }
            }
        }
    }

    for(int j = 1; j <= n; j++) {
        for(auto &[next, d] : g[j]) {
            if(dist[j] != INF && dist[next] > dist[j] + d) {
                return !(cout << -1 << '\n');
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }

    return 0;
}
