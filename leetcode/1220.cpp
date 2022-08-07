#include <vector>
#define MOD 1000000007

using namespace std;

class Solution {
public:
    vector<vector<int>> mm(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> ret(a.size(), vector<int>(b[0].size(), 0));
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                for(int k = 0; k < a[0].size(); k++){
                    ret[i][j] += (long long)a[i][k]*b[k][j]%MOD; 
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> M={ {0,1,0,0,0},      //Adjacency matrix of graph of the problem.
                                {1,0,1,0,0},
                                {1,1,0,1,1},
                                {0,0,1,0,1},
                                {1,0,0,0,0}};
        vector<vector<int>> result(5, vector<int>(5, 0));
        for(int i = 0; i < 5; i++) result[i][i] = 1;
        --n;
        int answer = 0;
        while(n){
            if(n&1) result = mm(M, result);
            n >>= 1;
            M = mm(M, M);
        }
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                answer = (answer + result[i][j]) % MOD;
            }
        }
        return answer;
    }
    // int countVowelPermutation(int n) {
    //     vector<vector<int>> d(n+1, vector<int>(5, 0));
    //     for(int i = 0; i < 5; i++) d[1][i] = 1;
    //     for(int i = 2; i <= n; i++){
    //         d[i][0] = ((d[i-1][1] + d[i-1][2]) % MOD + d[i-1][4]) % MOD;
    //         d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
    //         d[i][2] = (d[i-1][1] + d[i-1][3]) % MOD;
    //         d[i][3] = d[i-1][2];
    //         d[i][4] = (d[i-1][2] + d[i-1][3]) % MOD;
    //     }
    //     int answer = 0;
    //     for(int i = 0; i < 5; i++){
    //         answer = (answer + d[n][i]) % MOD;
    //     }
    //     return answer;
    // }
};