#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pii> g[1001];
int dist[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        g[s].emplace_back(e, t);
    }

    int s, e;
    cin >> s >> e;
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e9;
    }

    dist[s] = 0;
    priority_queue<pii> pq;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d *= -1;
        if(d > dist[now]) continue;
        for(auto [next, cost] : g[now]) {
            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                pq.emplace(-dist[next], next);
            }
        }
    }
 
    cout << dist[e] << '\n';

    return 0;
}