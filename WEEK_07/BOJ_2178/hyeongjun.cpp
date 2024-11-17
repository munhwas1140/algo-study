#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[100][100];
int main() {
    fastio;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dist, -1, sizeof(dist));
    queue<pii> q;
    q.emplace(0, 0);
    dist[0][0] = 1;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] == -1 && a[nx][ny] == '1') {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    cout << dist[n - 1][m - 1] << '\n';
    return 0;
}
