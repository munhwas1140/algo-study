#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool visited[12][6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;
    vector<string> a(12);
    for(int i = 0; i < 12; i++) {
        cin >> a[i];
    }

    int ans = 0;
    queue<pii> q;

    while(true) {
        bool flag = false;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(a[i][j] == '.') continue;
                int cnt = 0;
                visited[i][j] = true;
                vector<pii> pos;
                q.emplace(i, j);
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    cnt += 1;
                    pos.emplace_back(x, y);
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if(!visited[nx][ny] && a[nx][ny] == a[i][j]) {
                            q.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }

                if(cnt >= 4) {
                    flag = true;
                    for(const auto &[x, y] : pos) {
                        a[x][y] = '.';
                    }
                }
            }
        }


        if(!flag) break;
        ans += 1;

        for(int i = 11; i >= 0; i--) {
            for(int j = 0; j < 6; j++) {
                if(a[i][j] == '.') continue;
                int x = i + 1;
                while(x < 12 && a[x][j] == '.') x++;
                swap(a[i][j], a[x - 1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
