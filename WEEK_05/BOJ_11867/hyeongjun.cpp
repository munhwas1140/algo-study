#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[101][101];
int go(int n, int m) {
    if(n == 1 && m == 1) return 1;

    int &ret = dp[n][m];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = 1; i <= m / 2; i++) {
        ret = min(ret , 1 - go(i, m - i));
    }
    for(int i = 1; i <= n / 2; i++) {
        ret = min(ret , 1 - go(i, n - i));
    }
    return ret;
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << (go(n, m) == 0 ? 'A' : 'B') << '\n';
    return 0;
}


// go(1, 3) 1
// => go(1, 2) 0
// => go(1, 1) 1

// go(2, 3) 0
// => go(1, 2) 0 => go(1, 1) 1
// => go(1, 1)1


// go(n, m)