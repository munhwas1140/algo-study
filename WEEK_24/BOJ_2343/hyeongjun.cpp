#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[100000];
int check(int mid) {
    int cnt = 1;
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(now + a[i] > mid) {
            cnt += 1;
            now = a[i];
        } else {
            now += a[i];
        }
    }
    return cnt;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = *max_element(a, a + n);
    int e = 1e9;
    int ans = 0;
    while(s <= e) {
        int mid = (s + e) / 2;
        int cnt = check(mid);
        if(cnt <= m) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}