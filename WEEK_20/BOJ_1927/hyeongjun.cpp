#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int t; cin >> t;
    priority_queue<int> pq;

    while(t--) {
        int now; 
        cin >> now;
        if(now == 0) {
            if(pq.size() == 0) {
                cout << 0 << '\n';
            } else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(-now);
        }
    }

    return 0;
}