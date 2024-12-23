#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[50][50];
int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<pii> house;
    vector<pii> chicken;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                house.emplace_back(i, j);
            }
            if (a[i][j] == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }

    vector<int> permu(chicken.size() - m);
    for (int i = 0; i < m; i++) {
        permu.push_back(1);
    }

    int ans = 1e9;
    do {
        vector<int> a(house.size(), 1e9);

        for (int x = 0; x < chicken.size(); x++) {
            if (!permu[x])
                continue;
            auto [t1, t2] = chicken[x];

            for (int i = 0; i < house.size(); i++) {
                auto [t3, t4] = house[i];
                a[i] = min(a[i], abs(t3 - t1) + abs(t4 - t2));
            }
        }
        int now = 0;
        for (int x : a) {
            now += x;
        }
        ans = min(ans, now);
    } while (next_permutation(permu.begin(), permu.end()));
    cout << ans << '\n';

    return 0;
}