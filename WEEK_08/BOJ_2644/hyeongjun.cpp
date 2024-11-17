#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> g[101];
int main() {
    fastio;
    int n; cin >> n;
    int s, e; cin >> s >> e;
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    vector<int> dist(n + 1, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next : g[now]) {
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    cout << dist[e] << '\n';
    return 0;
}
