#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m; cin >> m;
    vector<tuple<int, int, int>> g(m);
    for(auto &[s, e, t] : g) {
        cin >> s >> e >> t;
        s--; e--;
    }

    map<vector<int>, int> dist;
    priority_queue<pair<int, vector<int>>> pq;
    dist[a] = 0;
    pq.emplace(0, a);

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d *= - 1;
        if(d > dist[now]) continue;

        for(const auto &[s, e, t] : g) {
            swap(now[s], now[e]);
            if(dist.count(now) == 0 || dist[now] > d + t) {
                dist[now] = d + t;
                pq.emplace(-dist[now], now);
            }
            swap(now[s], now[e]);
        }
    }

    sort(a.begin(), a.end());
    if(dist.count(a)) {
        cout << dist[a] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
