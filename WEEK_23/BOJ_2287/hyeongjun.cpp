#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int k, tc;
int main()
{
    fastio;
    cin >> k >> tc;

    set<ll> st[9];
    ll x = k;
    for (int i = 1; i <= 8; i++) {
        st[i].insert(x);
        x = x * 10LL + k;
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (ll x : st[j]) {
                for (ll y : st[i - j]) {
                    st[i].insert(x + y);
                    st[i].insert(x * y);
                    st[i].insert(x - y);
                    if (y != 0) {
                        st[i].insert(x / y);
                    }
                }
            }
        }
    }

    while (tc--) {
        int n;
        cin >> n;
        bool f = false;
        for (int i = 1; i <= 8; i++) {
            if (st[i].count(n)) {
                cout << i << '\n';
                f = true;
                break;
            }
        }
        if (!f) {
            cout << "NO" << '\n';
        }
    }

    return 0;
}