#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[20][20];
bool check[1 << 20];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    const int mask = (1 << n) - 1;
    check[mask] = true;

    for(int i = 1; i < (1 << n); i++) {
        if(check[i]) continue;
        check[mask ^ i] = true;

        vector<int> teamA, teamB;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) teamA.push_back(j);
            else teamB.push_back(j);
        }

        int A = 0;
        for(const int &x : teamA) {
            for(const int &y : teamA) {
                A += a[x][y];
            }
        }

        int B = 0;
        for(const int &x : teamB) {
            for(const int &y : teamB) {
                B += a[x][y];
            }
        }

        ans = min(ans, abs(A - B));
    }
    cout << ans << '\n';
    return 0;
}
