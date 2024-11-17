#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[101];
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
    int n; cin >> n;
    vector<pair<double, double>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<tuple<double, int, int>> g;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            g.emplace_back(sqrt(pow(a[i].first - a[j].first, 2) + pow(a[i].second - a[j].second, 2))
                ,i, j);
        }
    }
    sort(g.begin(), g.end());


    double ans = 0;
    int cnt = 0;
    for(auto [d, t1, t2] : g) {
        if(cnt == n - 1) break;
        t1 = find(t1);
        t2 = find(t2);
        if(t1 != t2) {
            set_union(t1, t2);
            ans += d;
            cnt += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
