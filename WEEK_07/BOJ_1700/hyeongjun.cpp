#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int ans = 0;
    set<int> st;
    for(int i = 0; i < k; i++) {
        if(st.size() != n) {
            st.insert(a[i]);
        } else if(st.count(a[i])) {
            continue;
        } else {
            int mx = -1, v = -1;
            for(int x : st) {
                bool f = true;
                for(int j = i + 1; j < k; j++) {
                    if(a[j] == x) {
                        if(mx < j) {
                            mx = j;
                            v = x;
                        }
                        f = false;
                        break;
                    }
                }
                if(f) {
                    mx = 1e9;
                    v = x;
                }
            }

            st.erase(v);
            st.insert(a[i]);
            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}

