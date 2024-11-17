#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int D(int now) {return (now * 2) % 10000;}
int S(int now) {return (now == 0 ? 9999 : now - 1);}
int L(int now) {return now % 1000 * 10 + now / 1000;}
int R(int now) {return now / 10 + now % 10 * 1000;}
char p[10000];
int pre[10000];
void print(int now) {
    if(pre[now] == -2) return;
    print(pre[now]);
    cout << p[now];
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(p,0,sizeof(p));
        memset(pre,-1,sizeof(pre));
        int s, e;
        cin >> s >> e;
    
        queue<int> q;
        q.push(s);
        pre[s] = -2;
        while(!q.empty()) {
<<<<<<< HEAD
            int now = q. front();
            if(now == st) break;
=======
            int now = q.front();
>>>>>>> 1c3d3341a36c56ebf2cc39c2ca58fec9707c6084
            q.pop();
            if(now == e) break;
            int a[4] = {D(now), S(now), L(now), R(now)};
            char ak[4] = {'D', 'S', 'L', 'R'};

<<<<<<< HEAD
            int mt = multi_two(now);
            int m1 = minus_one(now);Q
            int lt = left(now);
            int rt = right(now);

            if (p[mt] == -1) {
                q.push(mt);
                p[mt] = now;
                pc[mt] = 'D';
            }

            if (p[m1] == -1) {
                q.push(m1);
                p[m1] = now;
                pc[m1] = 'S';
            }
            if (p[lt] == -1) {
                q.push(lt);
                p[lt] = now;
                pc[lt] = 'L';
            }
            if (p[rt] == -1) {
                q.push(rt);
                p[rt] = now;
                pc[rt] = 'R';
=======
            for(int i = 0; i < 4; i++) {
                if(pre[a[i]] == -1) {
                    pre[a[i]] = now;
                    p[a[i]] = ak[i];
                    q.push(a[i]);
                }
>>>>>>> 1c3d3341a36c56ebf2cc39c2ca58fec9707c6084
            }
        }
        print(e);
        cout << '\n';
    } 
    return 0;
}