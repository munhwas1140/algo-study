#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const unsigned int mask = (1 << 21) - 2;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<unsigned int> a(n + 1);
    while(m--) {
        int q; cin >> q;
        int i, x;
        if(q == 1) {
            cin >> i >> x;
            a[i] |= 1 << x;
        } else if(q == 2) {
            cin >> i >> x;
            a[i] &= ~(1 << x);
        } else if(q == 3) {
            cin >> i;
            a[i] <<= 1;
        } else {
            cin >> i;
            a[i] >>= 1;
        }
        a[i] &= mask;
    }
    set<unsigned int> st;
    for(int i = 1; i <= n; i++) {
        st.insert(a[i]);
    }
    cout << st.size() << '\n';
    return 0;
}