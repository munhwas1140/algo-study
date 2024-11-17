#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), diff(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        diff[i + 1] = diff[i] + a[i];
    }

    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << diff[e] - diff[s - 1] << '\n';
    }
    return 0;
}
