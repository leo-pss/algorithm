#include <cstring>
#define MOD 1000000007

using namespace std;

class Solution {
public:
    int dp[52][52][51];
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1,0,-1,0};
    int solve(int m, int n, int curr_y, int curr_x, int move){
        if(curr_y == 0 || curr_x == 0 || curr_y == m+1 || curr_x == n+1) return 1;
        if(move == 0) return 0;
        if(dp[curr_y][curr_x][move] != -1) return dp[curr_y][curr_x][move];
        int ret = 0;
        for(int k = 0; k < 4; k++){
            int ny = curr_y + dy[k];
            int nx = curr_x + dx[k];
            ret = (ret + solve(m, n, ny, nx, move - 1)) % MOD;
        }
        return dp[curr_y][curr_x][move] = ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, startRow + 1, startColumn + 1, maxMove);
    }
};