#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dist[20001];
vector<pii> g[20001];
void init() {
    for(int i = 1; i <= 20000; i++) {
        dist[i] = 1e9;
    }
}
int main() {
    fastio;
    cin >> n >> m;
    init();
    int s; cin >> s;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].emplace_back(t2, t3);
    }

    priority_queue<pii> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d *= -1;
        if(dist[now] < d) continue;
        for(auto &next : g[now]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                pq.emplace(-dist[next.first], next.first);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dist[i] == 1e9) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }


    return 0;
}
