#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
    for(auto sk : skill) {
        int type = sk[0];
        int r1 = sk[1];
        int c1 = sk[2];
        int r2 = sk[3];
        int c2 = sk[4];
        int deg = sk[5];
        
        if(type == 1) deg *= -1;

        mp[r1][c1] += deg;
        mp[r1][c2 + 1] -= deg;
        mp[r2 + 1][c1] -= deg;
        mp[r2 + 1][c2 + 1] += deg;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mp[i][j + 1] += mp[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mp[i + 1][j] += mp[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] + mp[i][j] > 0) ans += 1;
        }
    }
    
    return ans;
}