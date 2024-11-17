#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct Node {
    bool check;
    Node *next[10];
};

bool go(Node *now, string &str, int idx) {
    if(now->check == true) return false;
    if(idx == str.size()) {
        return now->check = true;
    }
    int next = str[idx] - '0';
    if(now->next[next] == nullptr) {
        Node *newNode = new Node();
        now->next[next] = newNode;
    }
    return go(now->next[next], str, idx + 1);
}
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    bool f = true;
    Node *start = new Node();
    for(int i = 0; i < n; i++) {
        f &= go(start, a[i], 0);
        if(!f) break;
    }
    cout << (f ? "YES" : "NO") << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
