#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1);
    for(int &x : a) cin >> x;

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j - a[i] >= 0) {
                dp[j] += dp[j - a[i]];
            }
        }
    } 
    cout << dp[k] << '\n';
    
    return 0;
}