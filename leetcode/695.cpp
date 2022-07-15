#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int area(vector<vector<int>>& grid, int y, int x){
        int n = grid.size();
        int m = grid[0].size();
        int dy[4] = {0,1,0,-1};
        int dx[4] = {1,0,-1,0};
        queue<int> Q;
        
        int ret = 1;
        Q.push(y); Q.push(x);
        grid[y][x]=2;
        while(!Q.empty()){
            int ty = Q.front(); Q.pop();
            int tx = Q.front(); Q.pop();
            for(int k = 0; k < 4; k++){
                int ny = ty + dy[k];
                int nx = tx + dx[k];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || grid[ny][nx] != 1) continue;
                grid[ny][nx] = 2;
                Q.push(ny); Q.push(nx);
                ++ret;
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    answer = max(answer, area(grid, i, j));
                }
            }
        }
        return answer;
    }
};