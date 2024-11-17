#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int g[26][2];
void pre(int now) {
    cout << char(now + 'A');
    if(g[now][0] != 0) {
        pre(g[now][0]);
    }
    if(g[now][1] != 0) {
        pre(g[now][1]);
    }
}
void in(int now) {
    if(g[now][0] != 0) {
        in(g[now][0]);
    }
    cout << char(now + 'A');
    if(g[now][1] != 0) {
        in(g[now][1]);
    }
}
void post(int now) {
    if(g[now][0] != 0) {
        post(g[now][0]);
    }
    if(g[now][1] != 0) {
        post(g[now][1]);
    }
    cout << char(now + 'A');
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char tmp, l, r;
        cin >> tmp >> l >> r;
        int now = tmp - 'A';
        if(l != '.') g[now][0] = l - 'A';
        if(r != '.') g[now][1] = r - 'A';
    }
    pre(0);
    cout << '\n';

    in(0);
    cout << '\n';

    post(0);
    cout << '\n';
    return 0;
}
