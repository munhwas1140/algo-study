#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	fastio;
	int n;
	cin >> n;
	vector<pii> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}
	sort(a.begin(), a.end(), [](const pii &x, const pii &y) {
		if (x.second == y.second) {
			return x.first < y.first;
		}
		return x.second < y.second;
	});

	int ans = 0;
	int pre = -1;
	for (auto [x, y] : a) {
		if (x >= pre) {
			ans += 1;
			pre = y;
		}
	}

	cout << ans << '\n';
	return 0;
}