#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll dist[50001][2];
vector<pair<int,ll>> g[50001];

int main() {
    fastio;
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 2; j++) {
            dist[i][j] = 3e9;
        }
    }

    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].emplace_back(t2, t3);
        g[t2].emplace_back(t1, t3);
    }

    for(int i = 0; i < f; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].emplace_back(t2, -1LL);
    }

    dist[s][0] = 0;
    priority_queue<tuple<ll, int, int>> pq;
    pq.emplace(0, 0, s);
    while(!pq.empty()) {
        auto [d, state, now] = pq.top();
        pq.pop();
        d *= -1;
        if(d > dist[now][state]) {
            continue;
        }

        for(auto [next, cost] : g[now]) {
            if(cost == -1LL) {
                if(state == 1) continue;
                if(dist[next][1] > dist[now][state]) {
                    dist[next][1] = dist[now][state];
                    pq.emplace(-dist[next][1], 1, next);
                }
            } else {
                if(dist[next][state] > dist[now][state] + cost) {
                    dist[next][state ] = dist[now][state] + cost;
                    pq.emplace(-dist[next][state], state, next);
                }
            }
        }
    }

    cout << min(dist[t][0], dist[t][1]) << '\n';
    return 0;
}