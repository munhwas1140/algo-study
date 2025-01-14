#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
double p[4];
bool check[40][40];
double ans = 0.0;

double dfs(int cnt, int x, int y) {
    if(cnt == 0) {
        return 1.0;
    }

    double ret = 0;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!check[nx][ny]) {
            check[nx][ny] = true;
            ret += dfs(cnt - 1, nx, ny) * p[k];
            check[nx][ny] = false;
        }
    }
    return ret;
}

int main() {
    fastio;
    int n; cin >> n;

    int t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    p[0] = t1 / 100.0;
    p[1] = t2 / 100.0;
    p[2] = t3 / 100.0;
    p[3] = t4 / 100.0;
    
    check[20][20] = true;

    cout << fixed <<  setprecision(10);
    cout << dfs(n, 20, 20);

    return 0;
}