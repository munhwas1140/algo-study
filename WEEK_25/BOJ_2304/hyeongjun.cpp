#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;

    int mx = -1;
    vector<int> a(1001);
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        mx = max(t2, mx);
        a[t1] = t2;
    }

    int s = 1e9, e = -1;

    for(int i = 1; i <= 1000; i++) {
        if(a[i] == mx) {
            s = min(s, i);
            e = max(e, i);
        }
    }

    int ans = (e - s + 1) * mx;

    int now = 0;
    for(int i = 0; i < s; i++) {
        if(now < a[i]) {
            now = a[i];
        }
        ans += now;
    }

    now = 0;
    for(int i = 1001; i > e; i--) {
        if(now < a[i]) {
            now = a[i];
        }
        ans += now;
    }

    cout << ans << '\n';
    return 0;
}