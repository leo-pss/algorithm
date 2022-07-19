#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i = 1; i <= numRows; i++){
            vector<int> tmp(i, 0);
            tmp[0] = 1;
            for(int j = 1; j < i-1; j++){
                tmp[j] = answer[i-2][j-1] + answer[i-2][j];
            }
            if(i > 1) tmp[i-1] = 1;
            answer.push_back(tmp);
        }
        return answer;
    }
};