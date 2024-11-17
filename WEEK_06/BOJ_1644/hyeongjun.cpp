#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool p[4000001];
vector<int> prime;
int main() {
    fastio;
    for(int i = 2; i <= 4000000; i++) {
        if(!p[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 4000000; j += i) {
                p[j] = true;
            }
        }
    }

    int n; cin >> n;

    int sz = prime.size();

    int now = 0, s = 0, e = 0;
    int ans = 0;

    while(1) {
        if(now == n) ans += 1;
        if(now < n) {
            if(e == sz) break;
            now += prime[e++];
        } else {
            now -= prime[s++];
        }
    }

    cout << ans << '\n';
    return 0;
}
