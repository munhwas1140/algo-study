#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, r, c;
    cin >> n >> r >> c;

    int ans = 0;
    while(n > 0) {
        int rc = 1 << (n - 1);
        int cnt = 1 << ((n - 1) * 2);
        if(r >= rc) {
            if(c >= rc) {
                ans += cnt * 3;
                r -= rc;
                c -= rc;
            } else {
                ans += cnt * 2;
                r -= rc;
            }
        } else {
            if(c >= rc) {
                ans += cnt;
                c -= rc;
            } else {

            }
        }
        n -= 1;
    }
    cout << ans << '\n';
    return 0;
}