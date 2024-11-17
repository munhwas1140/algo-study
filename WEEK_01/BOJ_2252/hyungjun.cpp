#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int indeg[32001];
vector<int> g[32001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b] += 1;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        const int now = q.front();
        q.pop();
        cout << now << ' ';
        for(const int &next : g[now]) {
            indeg[next] -= 1;
            if(indeg[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << '\n';
    return 0;
}
