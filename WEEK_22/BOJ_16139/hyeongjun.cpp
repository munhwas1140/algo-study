#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt[26][200001];
int main()
{
	fastio;

	string str;
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		int now = str[i] - 'a';
        cnt[now][i + 1] = cnt[now][i] + 1;
        for(int j = 0; j < 26; j++) {
            if(j == now) continue;
            cnt[j][i + 1] = cnt[j][i];
        }
	}

	int q;
	cin >> q;
	while (q--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		cout << cnt[c - 'a'][r + 1] - cnt[c - 'a'][l] << '\n';
	}

	return 0;
}