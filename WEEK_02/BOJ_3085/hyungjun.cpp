#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int check(vector<string> &a) {
    int now;
    int ans = 1;
    for(int i = 0; i < n; i++) {
        now = 1;
        for(int j = 1; j < n; j++) {
            if(a[i][j] == a[i][j - 1]) now += 1;
            else now = 1;
            ans = max(ans, now);
        }

        now = 1;
        for(int j = 1; j < n; j++) {
            if(a[j][i] == a[j - 1][i]) now += 1;
            else now = 1;
            ans = max(ans, now);
        }
    }
    return ans;
}
int main() {
    fastio;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(a[i][j] == a[i][j + 1]) continue;
            swap(a[i][j], a[i][j + 1]);
            ans = max(ans,check(a));
            swap(a[i][j], a[i][j + 1]);
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == a[i + 1][j]) continue;
            swap(a[i][j], a[i + 1][j]);
            ans = max(ans,check(a));
            swap(a[i][j], a[i + 1][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
