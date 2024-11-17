#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, l;
int main() {
    fastio;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int p = -1e9;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - p < l) continue;
        p = a[i];
        ans += 1;
    }
    cout << ans << '\n';
    return 0;
}
