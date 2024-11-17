#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e4 + 7;
int dp[1001][10];
int main() {
    fastio;
    int n; cin >> n;

    for(int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}
