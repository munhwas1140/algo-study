#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int a[1000][1000];

int main()
{
    fastio;
    int n, m;
    cin >> m >> n;

    int cnt = 0;
    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            if (a[i][j] == 0) {
                q.emplace(i, j);
            } else if (a[i][j] == -1) {
                cnt += 1;
            }
        }
    }

    int mx = 0;
    while (!q.empty()) {
        const auto [x, y] = q.front();
        q.pop();
        mx = max(mx, a[x][y]);

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (a[nx][ny] == -2)
                continue;

            if (a[nx][ny] == -1) {
                a[nx][ny] = a[x][y] + 1;
                cnt -= 1;
                q.emplace(nx, ny);
            }
        }
    }

    if (cnt) {
        cout << -1 << '\n';
    } else {
        cout << mx << '\n';
    }

    return 0;
}