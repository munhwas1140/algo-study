#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
string a[1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sx, sy, mx;
void dfs(int x, int y, vector<vector<int>> &dist) {
    if(dist[x][y] > mx) {
        mx = dist[x][y];
        sx = x;
        sy = y;
    }
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == '#') continue;
        if(dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            dfs(nx, ny, dist);
        }
    }
}
void solve() {
    sx = sy = mx = -1;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];    
    }
    vector<vector<int>> dist1(n, vector<int>(m, -1)), dist2(n, vector<int>(m, -1));
    [&]() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '.') {
                    dist1[i][j] = 0;
                    dfs(i, j, dist1);
                    return ;
                }
            }
        }
    } ();
    if(mx == -1) {
        cout << "Maximum rope length is 0." << '\n';
        return ;
    }
    dist2[sx][sy] = 0;
    dfs(sx, sy, dist2);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dist2[i][j]);
        }
    }
    cout << "Maximum rope length is " << ans << ".\n";
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}