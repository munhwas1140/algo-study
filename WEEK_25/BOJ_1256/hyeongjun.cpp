#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int c[201][201];
string ans = "";
void go(int n, int m, int k) {
    if(n == 0) {
        ans += string(m, 'z');
        return ;
    } else if(m == 0) {
        ans += string(n, 'a');
        return ;
    }

    int cnt = c[n + m - 1][n - 1];
    if(k <= cnt) {
        ans += 'a';
        go(n - 1, m, k);
    } else {
        ans += 'z';
        go(n, m - 1, k - cnt);
    } 
}
int main() {
    fastio;
    int n, m, k;

    cin >> n >> m >> k;

    c[0][0] = c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= 200; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) c[i][j] = 1;
            else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                if(c[i][j] >= 1e9 + 10) c[i][j] = 1e9 + 10;
            }
        }
    }

    if(c[n + m][n] < k) {
        cout << -1 << '\n';
        return 0;
    }

    go(n, m, k);
    cout << ans << '\n';
    return 0;
}