#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[1000000];
int n, m;
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
}

ll set_cnt[1000000];
ll cnt[1000000];
ll cost[1000000];
vector<int> gr[1000000];

bool in_cycle[1000000];
bool finished[1000000];
bool visited[1000000];
void cycle_check_dfs(int now) {
    visited[now] = true;
    int next = (now * 2) % m;
    if(!visited[next]) {
        cycle_check_dfs(next);
    } else {
        if(!finished[next]) {
            in_cycle[now] = true;
            for(int i = next; i != now; i = (i * 2) % m) {
                in_cycle[i] = true;
            }
        }
    }
    finished[now] = true;
}

ll move(int now) {
    if(in_cycle[now]) return 0LL;

    ll cost = cnt[now];
    int next = (now * 2) % m;
    cnt[next] = cnt[next] + cnt[now];
    cnt[now] = 0LL;
    cost += move(next);
    return cost;
}

int find_start(int x) {
    if(in_cycle[x]) return x;
    int next = (x * 2) % m;
    return find_start(next);
}

// all cnt and cycle size
pll ddfs(int now) {
    visited[now] = true;
    int next = (now * 2) % m; 
    pll ret = {cnt[now], 1LL};
    if(!visited[next]) {
        pll next_p = ddfs(next);
        ret.first += next_p.first;
        ret.second += next_p.second;
    }
    return ret;
}

ll cost_dfs(int now, ll sz, ll nowsz) {
    visited[now] = true;
    ll ret = cnt[now] * ll(nowsz % sz) + cost[now];
    int next = (now * 2) % m;
    if(!visited[next]) {
        ret += cost_dfs(next, sz, nowsz - 1);
    }
    return ret;
}

ll ans_dfs(int now, ll all, ll cost, ll sz) {
    visited[now] = true;
    
    ll ans = cost;
    int next = (now * 2) % m;
    if(!visited[next]) {
        ll ncost = cost - ll(cnt[next] * (sz - 1)) + ll(all - cnt[next]);
        ans = min(ans, ans_dfs(next, all, ncost, sz));
    }
    return ans;
}

ll go(int start) {
    memset(visited, false, sizeof(visited));
    auto [all, sz] = ddfs(start);

    memset(visited, false, sizeof(visited));
    ll cost = cost_dfs(start, sz, sz);

    memset(visited, false, sizeof(visited));
    return ans_dfs(start, all, cost, sz);
}

ll ans_cnt = -1;
ll ans_cost = 1e18;
void dfs(int now) {
    for(int next : gr[now]) {
        if(!in_cycle[next]) {
            dfs(next);
            cnt[now] += cnt[next];
            cost[now] += cost[next] + cnt[next];
            cnt[next] = 0;
            cost[next] = 0;
        }
    }

    if(ans_cnt < cnt[now] || (ans_cnt == cnt[now] && ans_cost > cost[now])) {
        ans_cnt = cnt[now];
        ans_cost = cost[now];
    }
}

int main() {
    fastio;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] += 1LL;
    }

    memset(p, -1, sizeof(p));
    for(int i = 0; i < m; i++) {
        int next = (i * 2) % m;
        gr[next].push_back(i);
        set_union(i, next);
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        int x = find(a[i]);
        set_cnt[x] += 1;
        if(ans_cnt < set_cnt[x]) {
            st.clear();
            st.insert(x);
            ans_cnt = set_cnt[x];
        } else if (ans_cnt == set_cnt[x]) {
            st.insert(x);
        }
    }

    for(int i = 0; i < m; i++) {
        if(!finished[i]) {
            cycle_check_dfs(i);
        }
    }

    for(int i = 0; i < m; i++) {
        if(in_cycle[i]) {
            dfs(i);
        }
    }

    for(auto x : st) {
        int st = find_start(x);
        ans_cost = min(ans_cost, go(st));
    }

    cout << ans_cnt << ' ' << ans_cost << '\n';
    return 0;
}