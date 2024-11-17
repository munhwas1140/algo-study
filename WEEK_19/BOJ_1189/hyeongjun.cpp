#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string a[5];
int n, m, q;
bool visited[5][5];
int go(int x, int y, int cnt) {
    if(x == 0 && y == m - 1) {
        if(cnt == q) return 1;
        return 0;
    }

    int ret = 0;
    
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(a[nx][ny] == 'T') continue;
        if(!visited[nx][ny]) {
            visited[nx][ny] = true;
            ret += go(nx, ny, cnt + 1);
            visited[nx][ny] = false;
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    visited[n - 1][0] = true;
    cout << go(n - 1,0,1) << '\n';


    return 0;
}