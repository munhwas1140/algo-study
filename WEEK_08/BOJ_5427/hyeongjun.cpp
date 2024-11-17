#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> m >> n;
    vector<string> a(n);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<pii> fire;
    int sx, sy;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '@') {
                sx = i;
                sy = j;
            } else if(a[i][j] == '*') {
                fire.emplace_back(i, j);
            }
        }
    }

    queue<pii> f[2], q[2];
    dist[sx][sy] = 0;
    q[0].push({sx, sy});

    for(auto [x, y] : fire) {
        f[0].push({x, y});
    }
    for(int i = 0; ; i ^= 1) {

        while(!f[i].empty()) {
            auto [x, y] = f[i].front();
            f[i].pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(a[nx][ny] == '@' || a[nx][ny] == '.') {
                    a[nx][ny] = '*';
                    f[i ^ 1].push({nx, ny});
                }
            }
        }

        if(q[i].empty()) {
            cout << "IMPOSSIBLE" << '\n';
            return ;
        }

        while(!q[i].empty()) {
            auto [x, y] = q[i].front();
            q[i].pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist[x][y] + 1 << '\n';
                    return ;
                }
                if(a[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q[i ^ 1].push({nx, ny});
                }
            }
        }
    }
}


int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
