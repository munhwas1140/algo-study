#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[1000001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    p[x] = y;
}
int main() {
    fastio;
    memset(p, -1, sizeof(p));
    int n, m;
    cin >> n >> m;
    while(m--) {
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0) {
            set_union(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
