#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
ll a[100000];
bool f(ll v) {
    int cnt = 1;
    ll now = v;
    for(int i = 0; i < n; i++) {
        if(now >= a[i]) {
            now -= a[i];
        } else {
            now = v - a[i];
            cnt += 1;
        }
    }
    return cnt <= m;
}
int main() {
    fastio;
    cin >> n >> m;
    ll s = 0, e = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        e += a[i];
        s = max(s, a[i]);
    }
    ll ans = -1;
    while(s <= e) {
        ll mid = (s + e) / 2;
        if(f(mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
