#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }

    ll now = -1;
    for(int i = 0; i < k - 1; i++) {
        ll top = pq.top();
        pq.pop();
        now = top;
        for(ll x : a) {
            pq.push(top * x);
            if(now % x == 0) break;
        }
    }
    cout << pq.top() << '\n';
    return 0;
}