#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int ind[501];
vector<int> g[501];
bool check[501][501];
void solve() {
    memset(ind, 0, sizeof(ind));
    memset(check, false, sizeof(check));
    for(int i = 0; i < 501; i++) {
        g[i].clear();
    }

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        check[t1][t2] = check[t2][t1] = true;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(check[a[i]][a[j]]) {
                g[a[i]].push_back(a[j]);
                ind[a[j]] += 1; 
            } else {
                g[a[j]].push_back(a[i]);
                ind[a[i]] += 1; 
            }

        }
    }
    

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!ind[i]) {
            q.push(i);
        }
    }

    bool ambi = false;
    int cnt = 0;
    vector<int> ans;
    while(!q.empty()) {
        if(q.size() > 1) ambi = true;
        int now = q.front();
        q.pop();
        cnt += 1;
        ans.push_back(now);
        for(int next : g[now]) {
            ind[next] -= 1;
            if(!ind[next]) {
                q.push(next);
            }
        }
    }

    if(cnt != n) cout << "IMPOSSIBLE" << '\n';
    else if(ambi) cout << "?" << '\n';
    else {
        for(int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
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