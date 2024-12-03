#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAX = 99999;
int dist[1000000];
int calc(int now) {
    now *= 2;
    if(now >= MAX) return -1;

    string now_str = to_string(now);
    now -= int(pow(10, now_str.size() - 1));
    return now;
}
int main() {
    fastio;
    int n, t, g;
    cin >> n >> t >> g;

    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(dist[now] == t) continue;

        if(now + 1 <= MAX && dist[now + 1] == -1) {
            q.push(now + 1);
            dist[now + 1] = dist[now] + 1;
        }

        int next = calc(now);
        if(next == -1) continue;
        if(dist[next] == -1) {
            q.push(next);
            dist[next] = dist[now] + 1;
        }
    }

    if(dist[g] == -1) cout << "ANG" << '\n';
    else cout << dist[g] << '\n';
    return 0;
}