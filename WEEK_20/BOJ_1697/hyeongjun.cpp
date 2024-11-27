#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dist[200001];
const int MAX = 200000;
int main() {
    fastio;
    int a, b;
    cin >> a >> b;
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while(true) {
        int now = q.front();
        if(now == b) {
            return !(cout << dist[now] << '\n');
        }
        q.pop();
        if(now + 1 <= MAX and dist[now + 1] == -1) {
            dist[now + 1] = dist[now] + 1;
            q.push(now + 1);
        }
        
        if(now - 1 >= 0 and dist[now - 1] == -1) {
            dist[now - 1] = dist[now] + 1;
            q.push(now - 1);
        }

        if(now * 2 <= MAX and dist[now * 2] == -1) {
            dist[now * 2] = dist[now] + 1;
            q.push(now * 2);
        }
    }

    return 0;
}