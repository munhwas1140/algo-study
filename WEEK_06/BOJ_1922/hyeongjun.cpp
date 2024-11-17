#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[1001];
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
    memset(p, -1, sizeof(p));
    int n, m; cin >> n >> m;
    priority_queue<tuple<int,int,int>> pq;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        pq.emplace(-t3, t1, t2);
    }

    int cnt = 0, ans = 0;
    while(cnt < n - 1) {
        auto [t3, t1, t2] = pq.top();
        pq.pop();
        t3 *= -1;

        t1 = find(t1);
        t2 = find(t2);
        if(t1 != t2) {
            ans += t3;
            set_union(t1, t2);
            cnt++;
        }
    }
    cout << ans << '\n';


    return 0;
}
