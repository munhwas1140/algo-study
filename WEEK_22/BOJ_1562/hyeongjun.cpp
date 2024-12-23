#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1e9;
const int check = (1 << 10) - 1;

ll dp[111][11][1 << 10];
ll go(int now, int last, int state)
{
    if (now == 1) {
        if (last == 0)
            return 0LL;
        if (state == check)
            return 1LL;
        return 0LL;
    }

    ll &ret = dp[now][last][state];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    if (last == 0) {
        ret += go(now - 1, last + 1, state | (1 << (last + 1)));
        ret %= MOD;
    } else if (last == 9) {
        ret += go(now - 1, last - 1, state | (1 << (last - 1)));
        ret %= MOD;
    } else {
        ret += go(now - 1, last + 1, state | (1 << (last + 1)));
        ret %= MOD;
        ret += go(now - 1, last - 1, state | (1 << (last - 1)));
        ret %= MOD;
    }
    return ret;
}
int main()
{
    fastio;

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += go(n, i, 1 << i);
        ans %= MOD;
    }
    cout << ans << '\n';

    return 0;
}