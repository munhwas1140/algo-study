#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[501];
vector<tuple<int,int,int>> g;
void solve() {
    memset(dist, 0, sizeof(dist));
    g.clear();

    int n, m, w;
    cin >> n >> m >> w;

    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g.emplace_back(t1, t2, t3);
        g.emplace_back(t2, t1, t3);
    }

    for(int i = 0; i < w; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g.emplace_back(t1, t2, -t3);
    }

    for(int i = 0; i < n; i++) {
        for(auto &[s, e, t] : g) {
            if(dist[e] > dist[s] + t) {
                if(i == n -1) {
                    cout << "YES" << '\n';
                    return ;
                }
                dist[e] = dist[s] + t;

            }
        }
    }
    cout << "NO" << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}