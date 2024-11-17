#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    ll n; cin >> n;
    int cnt = 0;

    set<ll> st;
    for(ll i = 1; i <= 50001; i ++) {
        st.insert(i * i);
    }

    for(ll i = 1; i <= 50001; i ++) { 
        if(st.count(i * i - n)) {
            cnt += 1;
            cout << i << '\n';
        }
    }

    if(cnt == 0) cout << -1 << '\n';
    
    return 0;
}