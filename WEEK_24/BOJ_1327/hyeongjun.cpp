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
    string str = "";
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        str += c;
    }

    string ans_str = "";
    for(int i = 1; i <= n; i++) {
        ans_str += to_string(i);
    }

    set<string> st;
    st.insert(str);
    
    queue<pair<string, int>> q;
    q.emplace(str, 0);

    int ans = -1;
    while(!q.empty()) {
        auto [now, now_cnt] = q.front();
        q.pop();

        if(now == ans_str) {
            cout << now_cnt << '\n';
            return 0;
        }

        for(int i = 0; i <= n - k; i++) {
            reverse(now.begin() + i, now.begin() + i + k);
            if(st.count(now) == 0) {
                st.insert(now);
                q.emplace(now, now_cnt + 1);
            }
            reverse(now.begin() + i, now.begin() + i + k);
        }
    }
    cout << -1 << '\n';

    return 0;
}