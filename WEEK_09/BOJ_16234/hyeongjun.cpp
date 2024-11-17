#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, l, r;
int a[50][50];
bool visited[50][50];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int i, int j) {

    int cnt = 0;
    int sum = 0;
    
    vector<pii> list;
    queue<pii> q;
    q.emplace(i, j);
    visited[i][j] = true;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        cnt += 1;
        sum += a[x][y];
        list.emplace_back(x, y);

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            int diff = abs(a[x][y] - a[nx][ny]);
            if(l <= diff && diff <= r) {
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    
    int v = sum / cnt;
    for(auto [x, y] : list) {
        a[x][y] = v;
    }
}
int main() {
    fastio;
    cin >> n;
    cin >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int t = 0; ;t++) {
        bool f = false;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visited[i][j] || visited[nx][ny]) continue;
                    int diff = abs(a[i][j] - a[nx][ny]);
                    if(l <= diff && diff <= r) {
                        bfs(i, j);
                        f = true;
                    }
                }
            }
        }
        if(!f) {
            return !(cout << t << '\n');
        }
    }
    return 0;
}