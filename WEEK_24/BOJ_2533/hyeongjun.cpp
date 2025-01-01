#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[1000001];
int dp[1000001][2];
int go(int now, int p, int state) {
    
    int &ret = dp[now][state];
    if(ret != -1) return ret;
    ret = state;

    for(int next : g[now]) {
        if(next == p) continue;
        if(state == 0) {
            ret += go(next, now, 1);
        } else {
            ret += min(go(next, now, 0), go(next, now, 1));
        }
    }
    
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    memset(dp, -1, sizeof(dp));
    cout << min(go(1, 0,  0), go(1, 0, 1)) << '\n';

    return 0;
}