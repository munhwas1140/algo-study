#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int a[100001][2];
int dp[100001][3];

int n;

int go(int now, int state)
{
    if (now == n + 1) {
        return 0;
    }

    int &ret = dp[now][state];
    if (ret != -1)
        return ret;
    ret = 0;
    if (state != 0) {
        ret = a[now][state - 1];
    }

    int next = now + 1;

    if (state == 0) {
        ret += max({ go(next, 0), go(next, 1), go(next, 2) });
    }

    if (state == 1) {
        ret += max(go(next, 0), go(next, 2));
    }

    if (state == 2) {
        ret += max(go(next, 0), go(next, 1));
    }
    return ret;
}

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
}

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}