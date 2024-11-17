#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    cin >> str;

    // (, ) == 0
    // +, - == 1
    // *, / == 2
    stack<pair<char,int>> st;

    for(const char &c : str) {
        if (c == '(') {
            st.emplace('(', 0);
        } else if(c == ')') {
            while(st.top().first != '(') {
                cout << st.top().first;
                st.pop();
            }
            st.pop();
        } else if(c == '+' || c == '-') {
            while(!st.empty() && st.top().second >= 1) {
                cout << st.top().first;
                st.pop();
            }
            st.emplace(c, 1);
        } else if(c == '*' || c == '/') {
            while(!st.empty() && st.top().second >= 2) {
                cout << st.top().first;
                st.pop();
            }
            st.emplace(c, 2);
        } else {
            cout << c;
        }
    }
    while(!st.empty()) {
        cout << st.top().first;
        st.pop();
    }
    return 0;
}
// A+B*(C+D) => ABCD+*+
// A + B * C + D
// ABC*+

// A + B + (C + D)

// A*B*(C*D)
// AB*CD**
