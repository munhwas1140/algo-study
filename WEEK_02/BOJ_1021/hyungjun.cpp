#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        int sz = dq.size();
        int idx = 0;
        for(int j = 0; j < sz; j++) {
            if(dq[j] == a[i]) {
                idx = j;
                break;
            }
        }

        if(idx <= sz / 2) ans += idx;
        else ans += sz - idx;

        while(dq.front() != a[i]) {
            int now = dq.front();
            dq.pop_front();
            dq.push_back(now);
        }
        dq.pop_front();
    }
    cout << ans << '\n';
    return 0;
}
