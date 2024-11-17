#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> dp(n + 1);
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        if(i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
