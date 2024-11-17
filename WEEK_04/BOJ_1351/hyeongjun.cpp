#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<ll,ll> dp;
ll n, p, q;
ll go(ll now) {
    if(now == 0) return 1LL;

    if(dp.count(now)) {
        return dp[now];
    }
    dp[now] = go(now / p);
    dp[now] += go(now / q);
    return dp[now];
}
int main() {
    fastio;
    cin >> n >> p >> q;
    cout << go(n) << '\n';
    return 0;
}
