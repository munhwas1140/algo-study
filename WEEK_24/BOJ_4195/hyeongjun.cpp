#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[200001];
map<string, int> mp;
vector<string> a;
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] += p[y];
        p[y] = x;
    }
}
void solve() {
    memset(p, -1, sizeof(p));
    mp.clear();
    a.clear();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string t1, t2;
        cin >> t1 >> t2;

        if(!mp.count(t1)) {
            mp[t1] = a.size();
            a.push_back(t1);
        }

        if(!mp.count(t2)) {
            mp[t2] = a.size();
            a.push_back(t2);
        }

        int nt1 = mp[t1];
        int nt2 = mp[t2];
        
        set_union(nt1, nt2);
        int x = find(nt1);
        cout << -p[x] << '\n';
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}