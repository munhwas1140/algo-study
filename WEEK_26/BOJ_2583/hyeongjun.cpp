#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool check[100][100];
int main() {
    fastio;
    int n, m, k;
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                check[x][y] = true;
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(check[i][j]) continue;

            int cnt = 0;
            queue<pii> q;
            q.emplace(i, j);
            check[i][j] = true;
            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                cnt += 1;

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!check[nx][ny]) {
                        check[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }
    return 0;
}