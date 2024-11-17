#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void dfs(stack<char> &s) {
    if(s.empty()) return ;
    char top = s.top();
    s.pop();
    dfs(s);
    cout << top;
}
int main() {
    fastio;
    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        stack<char> l, r;
        for(const char &c : str) {
            if(c == '<') {
                if(!l.empty()) {
                    r.push(l.top());
                    l.pop();
                }
            } else if(c == '>') {
                if(!r.empty()) {
                    l.push(r.top());
                    r.pop();
                }
            } else if(c == '-') {
                if(!l.empty()) l.pop();
            } else {
                l.push(c);
            }
        }
        dfs(l);
        while(!r.empty()) {
            cout << r.top();
            r.pop();
        }
        cout << '\n';
    }
    return 0;
}
