#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
string a[50];
int mp[50][50];
int dist[50][50];
int p[300];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
}
int main() {
    fastio;
    cin >> n >> m;
    int sx, sy;
    vector<pii> pos(1);
    
    memset(mp, -1, sizeof(mp));
    for(int i = 0; i < n; i++) {
        cin >> a[i]; for(int j = 0; j < n; j++) {
            if(a[i][j] == 'S') {
                pos[0].first = i;
                pos[0].second = j;
                mp[i][j] = 0;
            } else if(a[i][j] == 'K') {
                mp[i][j] = pos.size();
                pos.push_back({i, j});
            }
        }
    }


    int sz = pos.size();
    vector<tuple<int,int,int>> cost_v;
    for(int i = 0; i < sz; i++) {
        memset(dist, -1, sizeof(dist));
        dist[pos[i].first][pos[i].second] = 0;
        queue<pii> q;
        q.emplace(pos[i].first, pos[i].second);

        while(!q.empty()) {
            auto [x, y] = q.front();
            if(mp[x][y] != -1 && mp[x][y] != i) {
                cost_v.push_back({dist[x][y], i, mp[x][y]});
            }
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(a[nx][ny] == '1') continue;
                if(dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }



    sort(cost_v.begin(), cost_v.end());
    
    int cnt = 0, ans = 0;
    memset(p, -1, sizeof(p));
    for(auto [v, t1, t2] : cost_v) {    
        if(cnt == sz - 1) break;
        t1 = find(t1);
        t2 = find(t2);
        if(t1 != t2) {
            set_union(t1, t2);
            ans += v;
            cnt += 1;
        }
    }

    if(cnt != sz - 1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}