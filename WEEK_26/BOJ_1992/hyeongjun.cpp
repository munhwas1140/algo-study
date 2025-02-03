#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a[64];
void go(int x, int y, int n) {
    int cnt[2] = {};
    for(int i = 0; i < n; i++)  {
        for(int j = 0; j < n; j++) {
            cnt[a[x + i][y + j] - '0']++;
        }
    }

    if(cnt[0] == n * n) {
        cout << 0;
    } else if(cnt[1] == n * n) {
        cout << 1;
    } else {
        cout << '(';
        go(x, y, n / 2);
        go(x, y + n / 2, n / 2);
        go(x + n / 2, y, n / 2);
        go(x + n / 2, y + n / 2, n / 2);
        cout << ')';
    } 
}
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, 0, n);

    return 0;
}