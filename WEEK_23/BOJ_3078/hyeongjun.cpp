#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt[21];
int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    deque<string> dq;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        while (dq.size() > k) {
            cnt[dq.front().size()]--;
            dq.pop_front();
        }

        ans += ll(cnt[str.size()]);

        dq.push_back(str);
        cnt[str.size()] += 1;
    }

    cout << ans << '\n';
    return 0;
}