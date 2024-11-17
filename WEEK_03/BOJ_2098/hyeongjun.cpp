#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int w[16][16];
int dp[16][1<<16];
int go(int now, int state) {
    if(state == (1 <<  n) - 1) {
        return w[now][0] != 0 ? w[now][0] : 1e9;
    }

    int &ret = dp[now][state];
    if(ret != -1) {
        return ret;
    }
    ret = 1e9;

    for(int i = 0; i < n; i++) {
        if(state & 1 << i || w[now][i] == 0) continue;
        ret = min(ret, go(i, state | (1<<i)) + w[now][i]);
    }

    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0, 1);
    return 0;
}
