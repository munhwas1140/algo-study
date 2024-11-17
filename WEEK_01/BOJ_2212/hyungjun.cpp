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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> diff(a.size() - 1);
    for(int i = 0; i < a.size() - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
    sort(diff.begin(), diff.end());
    int ans = 0;
    for(int i = 0; i < (n - 1) - (k - 1); i++) {
        ans += diff[i];
    }
    cout << ans << '\n';

    return 0;
}