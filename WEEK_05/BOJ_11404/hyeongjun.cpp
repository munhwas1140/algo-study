#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[101][101];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        if(dist[s][e] == 0 || dist[s][e] > t) {
            dist[s][e] = t;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || dist[i][k] == 0 || dist[k][j] == 0) continue;
                if(dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
