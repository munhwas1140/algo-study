#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int t[501], ind[501], dist[501];
vector<int> g[501];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        while(true) {
            int tmp; cin >> tmp;
            if(tmp == -1) break;
            g[tmp].push_back(i);
            ind[i] += 1;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            dist[i] = t[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(const auto &next : g[now]) {
            dist[next] = max(dist[now] + t[next], dist[next]);
            ind[next] -= 1;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << '\n';
    }

    return 0;
}
