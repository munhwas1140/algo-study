#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[1001];
bool visited[1001];

void dfs(int now) {
    visited[now] = true;
    cout << now << ' ';
    for(const int &next : g[now]) {
        if(visited[next] == false) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        const int now = q.front();
        cout << now << ' ';
        q.pop();
        for(const int &next : g[now]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    fastio;
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(s);
    cout << '\n';
    memset(visited, false, sizeof(visited));
    bfs(s);
    cout << '\n';
    return 0;
}
