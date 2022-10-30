#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<vector<int>> Q;
        Q.push({0, 0, 0, k});
        while(!Q.empty()){
            auto now = Q.front(); Q.pop();
            int y = now[0], x = now[1];
            if(y < 0 || y >= m || x < 0 || x >= n) continue;
            if(y == m - 1 && x == n - 1) return now[2];
            if(grid[y][x] == 1){
                if(now[3] > 0) --now[3];
                else continue;
            }
            if(visited[y][x] != -1 && visited[y][x] >= now[3]) continue;
            visited[y][x] = now[3];
            for(int k = 0; k < 4; k++)
                Q.push({y+dy[k], x+dx[k], now[2]+1, now[3]});
        }
        
        return -1;
    }
private:
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
};