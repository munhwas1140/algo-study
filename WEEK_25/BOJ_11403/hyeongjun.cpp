#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int g[100][100];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }


    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][k] && g[k][j]) {
                    g[i][j] = 1;
                }
            }
        }
    }
     
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}