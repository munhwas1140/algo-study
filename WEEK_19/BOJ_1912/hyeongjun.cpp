#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), dp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = -10000;
    for(int i = 0; i < n; i++) {
        dp[i] = a[i];
        if(i > 0 && dp[i - 1] + a[i] > dp[i]) {
            dp[i] = dp[i - 1] + a[i];
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}