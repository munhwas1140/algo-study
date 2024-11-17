#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    deque<pii> dq;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        dq.emplace_back(tmp, i);
    }

    int cnt = 1;
    while(1) {
        int sz = dq.size();
        pii now = dq.front();
        int idx = -1;
        for(int i = 1; i < dq.size(); i++) {
            if(dq[i].first > now.first) {
                idx = i;
                break;
            }
        }

        if(idx != -1) {
            for(int i = 0; i < idx; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            if(now.second == m) {
                cout << cnt << '\n';
                return ;
            }
            dq.pop_front();
            cnt++;
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
