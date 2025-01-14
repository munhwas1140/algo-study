#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dz[] = {1, -1};
int l, r, c;
int dist[30][30][30];
int main() {
    fastio;
    while(true) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        vector<vector<string>> a(l, vector<string>(r));
        int sx, sy, sz;
        int ex, ey, ez;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                cin >> a[i][j];
                for(int k = 0; k < c; k++) {
                    if(a[i][j][k] == 'S') {
                        sz = i;
                        sx = j;
                        sy = k;
                    } else if(a[i][j][k] == 'E') {
                        ez = i;
                        ex = j;
                        ey = k;
                    }
                }
            }
        }

        memset(dist, -1,sizeof(dist));
        dist[sz][sx][sy] = 0;
        queue<tuple<int,int,int>> q;
        q.emplace(sz, sx, sy);
        while(!q.empty()) {
            auto [z, x, y] = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(a[z][nx][ny] == '#') continue;
                if(dist[z][nx][ny] == -1) {
                    dist[z][nx][ny] = dist[z][x][y] + 1;
                    q.emplace(z, nx, ny);
                }
            }

            for(int k = 0; k < 2; k++) {
                int nz = z + dz[k];
                if(nz < 0 || nz >= l) continue;
                if(a[nz][x][y] == '#') continue;
                if(dist[nz][x][y] == -1) {
                    dist[nz][x][y] = dist[z][x][y] + 1;
                    q.emplace(nz, x, y);
                }
            }
        }

        if(dist[ez][ex][ey] != -1) {
            cout << "Escaped in " << dist[ez][ex][ey] << " minute(s)." << '\n';
        } else {
            cout << "Trapped!" << '\n';
        }
    }
    return 0;
}