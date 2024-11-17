#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool p[250000];
int psum[250000];
int main() {
    fastio;
    p[0] = p[1] = true;
    for(int i = 2; i < 250000; i++) {
        if(!p[i]) {
            for(int j = i + i; j < 250000; j += i) {
                p[j] = true;
            }
        }
    }

    for(int i = 2; i < 250000; i++) {
        psum[i] = psum[i - 1] + !p[i];
    }


    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        cout << psum[2 * n] - psum[n] << '\n';
    }
    return 0;
}
