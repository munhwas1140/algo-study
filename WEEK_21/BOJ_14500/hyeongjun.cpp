#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[500][500];
vector<vector<vector<int>>> pos = {
    {
        {1, 1, 1, 1}
    },
    {
        {1}, 
        {1},
        {1}, 
        {1}
    },
    {
        {1, 1},
        {1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0}
    },
    {
        {1, 1, 1},
        {0, 1, 0}
    },
    {
        {1, 0, 0},
        {1, 1, 1}
    },
    {
        {0, 1, 0},
        {1, 1, 1}
    },
    {
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 0},
        {0, 1, 1}
    },
    {
        {0, 1, 1},
        {1, 1, 0}
    },
    {
        {1, 1},
        {0, 1},
        {0, 1}
    },
    {
        {0, 1},
        {1, 1},
        {0, 1}
    },
    {
        {0, 1},
        {0, 1},
        {1, 1}
    },
    {
        {1, 1},
        {1, 0},
        {1, 0}
    },
    {
        {1, 0},
        {1, 1},
        {1, 0}
    },
    {
        {1, 0},
        {1, 0},
        {1, 1}
    },
    {
        {1, 0},
        {1, 1},
        {0, 1}
    },
    {
        {0, 1},
        {1, 1},
        {1, 0}
    }
};

int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(vector<vector<int>> v : pos) {
        int r = v.size();
        int c = v[0].size();
        for(int i = 0; i <= n - r; i++) {
            for(int j = 0; j <= m - c; j++) {
                int tmp = 0;
                for(int x = 0; x < r; x++) {
                    for(int y = 0; y < c; y++) {
                        tmp += a[i + x][j + y] * v[x][y];
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}