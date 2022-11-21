#include <queue>
#include <vector>

using namespace std;

class Solution {
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1,0,-1,0};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        
        queue<int> Q;
        Q.push(entrance[0]); Q.push(entrance[1]); Q.push(0); check[entrance[0]][entrance[1]] = true;
        while(!Q.empty()){
            int ty = Q.front(); Q.pop();
            int tx = Q.front(); Q.pop();
            int cnt = Q.front(); Q.pop();
            for(int k = 0; k < 4; k++){
                int ny = ty + dy[k], nx = tx + dx[k];
                if(ny<0 || nx<0 || ny>=n || nx>=m || maze[ny][nx]=='+' || check[ny][nx]) continue;
                if(ny==0 || ny==n-1 || nx==0 || nx==m-1) return cnt+1;
                Q.push(ny); Q.push(nx); Q.push(cnt+1);
                check[ny][nx] = true;
            }
        }
        return -1;
    }
};