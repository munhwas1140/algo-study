#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int ans = 1e9 + 7;
    for(int i = 1; i < (1 << n); i++) {
        int t1 = 1, t2 = 0;
        for(int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                t1 *= a[j];
                t2 += b[j];
            }
        }
        ans = min(ans, abs(t1 - t2));
    }
    cout << ans << '\n';
    return 0;
}
