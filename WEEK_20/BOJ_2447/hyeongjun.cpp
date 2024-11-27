#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool a[3000][3000];
void mark(int x, int y, int sz) {
    for(int i = x; i < x + sz; i++) {
        for(int j = y; j < y + sz; j++) {
            a[i][j] = true;
        }
    }
}
void go(int r, int c, int sz) {
    if(sz == 1) return;
    sz /= 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            go(r + sz * i, c + sz * j, sz);
        }
    }
    mark(r + sz, c + sz, sz);
}
int main() {
    fastio;
    int n; cin >> n;
    go(0, 0, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (a[i][j] ? ' ' : '*');
        }
        cout << '\n';
    }
    return 0;
}