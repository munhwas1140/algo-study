#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[10000001];
int main()
{
	fastio;
	check[0] = check[1] = true;
	vector<ll> p;
	for (ll i = 2; i <= 10000000; i++) {
		if (!check[i]) {
			for (ll j = i; j <= 10000000; j += i) {
				check[j] = true;
			}
			for (__int128 j = i * i; j <= 1e14; j *= i) {
				p.push_back(j);
			}
		}
	}
	sort(p.begin(), p.end());

	ll a, b;
	cin >> a >> b;
	auto t1 = lower_bound(p.begin(), p.end(), a);
	auto t2 = lower_bound(p.begin(), p.end(), b);

	ll ans = t2 - t1;
	if (*t2 == b)
		ans += 1;

	cout << ans << '\n';

	return 0;
}