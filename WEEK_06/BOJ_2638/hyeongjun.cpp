#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int cnt[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }


    int ans = 0;
    while(true) {
        bool f = [&] () {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(a[i][j] == 1) {
                        return false;
                    }
                }
            }
            return true;
        }();
        if(f) break;

        memset(visited ,false, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));

        queue<pii> q;
        q.emplace(0, 0);
        visited[0][0] = true;
        set<pii> st;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(!visited[nx][ny] && a[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }

                if(a[nx][ny] == 1) {
                    cnt[nx][ny] += 1;
                    if(cnt[nx][ny] >= 2) st.insert({nx, ny});
                }
            }
        }

        for(pii x : st) {
            a[x.first][x.second] = 0;
        }
        ans += 1;
    }
    cout << ans << '\n';
    return 0;
}
