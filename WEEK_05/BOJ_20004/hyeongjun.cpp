#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[32][32];
int go(int now, int sz) {
    if(now >= 31) return 0;

    int &ret = dp[now][sz];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = 1; i <= sz; i++) {
        if(now + i > 31) continue;
        ret = min(ret, 1 - go(now + i, sz));
    }
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        if(go(0, i) == 1) cout << i << '\n';
    }

    return 0;
}
