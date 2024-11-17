#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[102];
void solve() {
    for(int i = 0; i < 101; i++) g[i].clear();
    int n; 
    cin >> n;

    vector<pii> a(n + 2);
    for(int i = 0; i < n + 2; i++) {
        cin >> a[i].first >> a[i].second;
        for(int j = 0; j < i; j++) {
            int cost = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
            if(cost <= 1000) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n + 2);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next : g[now]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    if(visited[n + 1]) {
        cout << "happy" << '\n';
    } else {
        cout << "sad" << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}