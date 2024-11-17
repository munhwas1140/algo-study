#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[100001];
int p[100001];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    memset(p, -1, sizeof(p));
    p[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next : g[now]) {
            if(p[next] == -1) {
                p[next] = now;
                q.push(next);
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }

    return 0;
}
