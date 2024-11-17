#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, a[1000000];
ll m;

ll check(int now) {
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ret += ll(max(0, a[i] - now));
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    int e = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        e = max(e, a[i]);
    }

    int s = 0;

    int ans = 0;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(check(mid) >= m) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
