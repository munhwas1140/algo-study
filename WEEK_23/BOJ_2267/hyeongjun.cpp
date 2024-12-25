#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main()
{
    fastio;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '0')
                continue;

            queue<pii> q;
            q.emplace(i, j);
            a[i][j] = '0';
            int cnt = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                cnt += 1;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (a[nx][ny] == '1') {
                        q.emplace(nx, ny);
                        a[nx][ny] = '0';
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << '\n';
    }
    return 0;
}