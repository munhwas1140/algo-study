#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, l;
ll k;
int c[32][32];

void comb_init()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
    }
}

void go(int now, int rem, ll cnt)
{
    if (now == 0)
        return;
    int x = 0;
    for (int i = 0; i <= rem; i++) {
        x += c[now - 1][i];
    }

    if (cnt <= x) {
        cout << 0;
        go(now - 1, rem, cnt);
    } else {
        cout << 1;
        go(now - 1, rem - 1, cnt - x);
    }
}
int main()
{
    fastio;
    comb_init();
    cin >> n >> l >> k;
    go(n, l, k);
    return 0;
}
