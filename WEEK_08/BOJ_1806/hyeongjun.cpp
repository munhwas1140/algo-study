#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = 0, e = 1;
    int now = a[s];
    int ans = 0;
    while(s < e) {
        if(now < m) {
            if(e == n) break;
            now += a[e];
            e += 1;
        } else if(now >= m) {
            if(ans == 0 || ans > e - s) {
                ans = e - s;
            }
            now -= a[s];
            s += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
