#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[10000];
int check(int mid) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > mid) sum += mid;
        else sum += a[i];
    }
    return sum;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    int s = 1;
    int e = *max_element(a, a + n);
    int ans = 0;
    while(s <= e) {
        int mid = (s + e) / 2;
        
        int now = check(mid);
        if(now <= m) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}