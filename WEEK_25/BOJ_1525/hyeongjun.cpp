#include <bits/stdc++.h>
#include <map>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
map<string, int> mp;
int main() {
    fastio;
    string start = "";
    for(int i = 0 ; i < 9; i++) {
        char c; cin >> c;
        start += c;
    }

    mp[start] = 0;
    queue<string> q;
    q.push(start);

    while(!q.empty()) {
        string now = q.front();
        q.pop();
        int now_dist = mp[now];
        int idx = now.find('0');
        int x = idx / 3;
        int y = idx % 3;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            swap(now[idx], now[nx * 3 +  ny]);
            if(!mp.count(now)) {
                mp[now] = now_dist + 1;
                q.push(now);
            }
            swap(now[idx], now[nx * 3 +  ny]);
        }
    }
    
    if(mp.count("123456780")) {
        cout << mp["123456780"] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}