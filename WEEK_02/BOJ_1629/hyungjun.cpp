#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = 1LL;
    ll now = a;
    while(b) {
        if(b & 1) {
            ans *= now;
            ans %= c;
        }
        now = now * now;
        now %= c;
        b >>= 1;
    }
    cout << ans << '\n';
    return 0;
}
