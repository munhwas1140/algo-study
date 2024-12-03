#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool p[1000001];
int check[1000001];
vector<int> prime;
int go(int now) {
    if(now == 1 || check[now] == 1) return 1;
    if(check[now] == 0) return 0;

    check[now] = 0;

    int tmp = 0, x = now;
    while(x != 0) {
        tmp += (x % 10) * (x % 10);
        x /= 10;
    }

    return check[now] = go(tmp);
}
int main() {
    fastio;
    int n; cin >> n;
    
    for(int i = 2; i <= n; i++)  {
        if(!p[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= n; j += i) {
                p[j] = true;
            }
        }
    }

    memset(check, -1, sizeof(check));
    for(int x : prime) {
        if(go(x) == 1) {
            cout << x << '\n';
        }
    }

    return 0;
}