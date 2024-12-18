#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int s, e;
vector<pii> g[1000];
int main()
{
	fastio;
	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		g[t1].emplace_back(t2, t3);
		g[t2].emplace_back(t1, t3);
	}

	queue<pii> q;
	vector<int> dist(n, 0);
	q.emplace(s, 1e9);
	while (!q.empty()) {
		auto [now, pos] = q.front();
		q.pop();

		for (auto [next, cost] : g[now]) {
			int n_pos = min(cost, pos);
			if (dist[next] < n_pos) {
				dist[next] = n_pos;
				q.emplace(next, n_pos);
			}
		}
	}

	cout << dist[e] << '\n';

	return 0;
}