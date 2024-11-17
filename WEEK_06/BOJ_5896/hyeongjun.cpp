#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<pll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&] (const pii &u, const pii &v) {
        return u.second < v.second || u.second == v.second && u.first < v.first;
    });

    priority_queue<ll, vector<ll>, greater<>> pq;

    ll cost = 0;
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(cost + a[i].second <= m) {
            cost += a[i].second;
            ans++;
            pq.push(a[i].first - a[i].second);
        }
    }

    for(int i = k; i < n; i++) {
        if(!pq.empty() && pq.top() + a[i].second < a[i].first) {
            if(cost + pq.top() + a[i].second <= m) {
                cost += pq.top() + a[i].second;
                pq.pop();
                pq.push(a[i].first - a[i].second);
                ans++;
            }
        } else {
            if(cost + a[i].first <= m) {
                cost += a[i].first;
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}