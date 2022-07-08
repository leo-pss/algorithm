#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> d(m, vector<vector<int>>(n+1, vector<int>(target+1, INF)));
        // d[i][j][k] : i개의 집, 마지막 집 색깔 j, neighbor : k개일때 최소 cost
        if(houses[0] == 0){
            for(int i = 1; i <= n; i++){
                d[0][i][1] = cost[0][i-1];
            }
        }
        else{
            d[0][houses[0]][1] = 0;
        }
        for(int i = 1; i < m; i++){
            int color = houses[i];
            if(color != 0){
                for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= target; k++){
                        if(color == j) d[i][color][k] = min(d[i][color][k], d[i-1][j][k]);
                        else d[i][color][k] = min(d[i][color][k], d[i-1][j][k-1]);
                    }       
                }
            }
            else{
                for(int j = 1; j <= n; j++){ // j : 칠할 색깔
                    for(int jj = 1; jj <= n; jj++){ // jj : 이전 색깔
                        for(int k = 1; k <= target; k++){
                            if(j == jj) d[i][j][k] = min(d[i][j][k], d[i-1][j][k] + cost[i][j-1]);
                            else d[i][j][k] = min(d[i][j][k], d[i-1][jj][k-1] + cost[i][j-1]);
                        }
                    }
                }
            }
        }
        int answer = INF;
        for(int i = 1; i <= n; i++){
            answer = min(answer, d[m-1][i][target]);
        }
        return answer != INF ? answer : -1;
    }
};