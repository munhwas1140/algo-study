#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int a[100][100];
bool visited[100][100];
int n;
void dfs(int now, int x, int y) {
    visited[x][y] = true;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 ||  nx >= n || ny < 0 || ny >= n || a[nx][ny] <= now) continue;
        if(!visited[nx][ny]) {
            dfs(now, nx, ny);
        }
    }
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1;
    for(int i = 1; i <= 100; i++) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(a[x][y] > i && !visited[x][y]) {
                    cnt += 1;
                    dfs(i, x, y);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
