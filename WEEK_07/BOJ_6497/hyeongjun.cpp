#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[200000];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
}
int main() {
    fastio;
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < n; i++) {
            p[i] = -1;
        }

        int sum = 0;
        vector<tuple<int,int,int>> a(m);
        for(auto &[t1, t2, t3] : a) {
            cin >> t2 >> t3 >> t1;
            sum += t1;
        }
        sort(a.begin(), a.end());

        int tsum = 0, cnt = 0;
        for(auto [t1, t2, t3] : a) {
            if(cnt == n - 1) break;
            t2 = find(t2);
            t3 = find(t3);
            if(t2 != t3) {
                set_union(t2, t3);
                tsum += t1;
                cnt++;
            }
        }
        cout << sum - tsum << '\n';
    }

    return 0;
}
