#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dy[4] = {0,1,0,-1};
        int dx[4] = {1,0,-1,0};
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    queue<int> Q;
                    Q.push(i); Q.push(j);
                    while(!Q.empty()){
                        int ty = Q.front(); Q.pop();
                        int tx = Q.front(); Q.pop();
                        for(int k = 0; k < 4; k++){
                            int ny = ty + dy[k];
                            int nx = tx + dx[k];
                            if(ny < 0 || nx < 0 || ny >= n || nx >= m || grid[ny][nx] == '0') continue;
                            Q.push(ny); Q.push(nx);
                            grid[ny][nx] = '0';
                        }
                    }
                    ++answer;
                }
            }
        }
        return answer;
    }
};