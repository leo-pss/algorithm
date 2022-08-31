#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> visited;
    void dfs(vector<vector<int>>& h, int y, int x, int prev_h, int prev_v){
        if(y < 0 || y >= h.size() || x < 0 || x >= h[0].size()) return;
        if(h[y][x] < prev_h || (visited[y][x] & prev_v) == prev_v) return;
        visited[y][x] |= prev_v;
        if(visited[y][x] == 3) answer.push_back({y,x});
        dfs(h, y+1, x, h[y][x], visited[y][x]);
        dfs(h, y, x+1, h[y][x], visited[y][x]);
        dfs(h, y-1, x, h[y][x], visited[y][x]);
        dfs(h, y, x-1, h[y][x], visited[y][x]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        visited.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            dfs(heights, i, 0, -1e9, 1);
            dfs(heights, i, m-1, -1e9, 2);
        }
        for(int i = 0; i < m; i++){
            dfs(heights, 0, i, -1e9, 1);
            dfs(heights, n-1, i, -1e9, 2);
        }
        return answer;
    }
};