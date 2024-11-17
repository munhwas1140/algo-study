#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[10][10];
int cnt[5];
bool fil(int x, int y, int sz, int v) {
    if(v == -1) {
        for(int i = x; i <= x + sz; i++) {
            for(int j = y; j <= y + sz; j++) {
                if(a[i][j] == 0) return false;
            }
        }
    }
    for(int i = x; i <= x + sz; i++) {
        for(int j = y; j <= y + sz; j++) {
            a[i][j] += v;
        }
    }
<<<<<<< HEAD
=======
    
>>>>>>> daa260256e20a28e8cbf54e3e2e868dde89c1f73
    return true;
}
int go(int now) {
    if(now == 100) {
        return 0;
    }
    int x = now / 10;
    int y = now % 10;
    int ret = 1e9;
    if(a[x][y] == 1) {
        for(int i = 0; i < 5; i++) {
            if(x + i >= 10 || y + i >= 10) break;
            if(cnt[i] > 0 && fil(x, y, i, -1)) {
                cnt[i]--;
                ret = min(ret, go(now + 1) + 1);
                fil(x, y, i, 1);
                cnt[i]++;
            }
        }
    } else {
        ret = go(now + 1);
    }
    return ret;
}
int main() {
    fastio;
    for(int i = 0; i < 5; i++) {
        cnt[i] = 5;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }
    int ans = go(0);
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}