#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b;
int dp[1001][1001];
int go(int ai, int bi) {
    if(ai < 0 || bi < 0) return 0;

    int &ret = dp[ai][bi];
    if(ret != -1) return ret;
    ret = go(ai - 1, bi);
    ret = max(ret, go(ai, bi - 1));
    if(a[ai] == b[bi]) {
        ret = max(ret, go(ai - 1, bi - 1) + 1);
    }
    return ret;
}

void trace(int ai, int bi) {
    if(ai < 0 || bi < 0) return ;
    int now = go(ai, bi);
    if(a[ai] == b[bi] && go(ai - 1, bi - 1) + 1 == now) {
        trace(ai - 1, bi - 1);
        cout << a[ai];
    } else {
        if(now == go(ai - 1, bi)) {
            trace(ai - 1, bi);
        } else {
            trace(ai, bi - 1);
        }
    }
}
int main() {
    fastio;
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    int ret = go(a.size() - 1, b.size() - 1);
    cout << ret << '\n';
    if(ret != 0) trace(a.size() - 1, b.size() - 1);
    return 0;
}
