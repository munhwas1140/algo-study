#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<pii> g[1000];
vector<tuple<int, int, int>> tp;
vector<int> pos;
int n, m, dist[1000];
bool visited[1000];
void init() {
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));
    tp.clear();
    for(int i = 0; i < 1000; i++) g[i].clear();
}
int main() {
    fastio;
    int tc; cin >> tc;
    for(int T = 1; T <= tc; T++) {
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g[t1].push_back({t2, t3});
            tp.push_back(make_tuple(t1, t2, t3));
        }

        for(int i = 0; i < n - 1; i++) {
            for(auto &[now, next, cost] : tp) {
                if(dist[next] > dist[now] + cost) {
                    dist[next] = dist[now] + cost;
                }
            }
        }

        queue<int> q; 
        for(auto &[now, next, cost] : tp) {
            if(dist[next] > dist[now] + cost) {
                q.push(next); visited[next] = true;
                dist[next] = dist[now] + cost;
            }
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            for(auto &next : g[now]) {
                if(!visited[next.first]) {
                    visited[next.first] = true;
                    q.push(next.first);
                }
            }
        }

        cout << "Case #" << T << ": ";
        if(visited[0]) cout << "possible" << '\n';
        else cout << "not possible" << '\n';
    }     
      
    return 0;
}