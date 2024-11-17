#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000001];
int f, s, g, u, d;
int go(int now) {
    if(now < 1 || now > f) return 1e9;
    if(now == g) return 0;

    int &ret = dp[now];
    if(ret != -1) {
        return ret;
    }
    ret = 1e9;
    ret = min(ret, go(now + u) + 1);
    ret = min(ret, go(now - d) + 1);
    return ret;
}
int main() {
    fastio;
    cin >> f >> s >> g >> u >> d;

    memset(dp, -1, sizeof(dp));

    int ans = go(s);
    if(ans == 1e9) {
        cout << "use the stairs" << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
