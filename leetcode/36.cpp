#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0};
        bool col[9][9] = {0};
        bool sub_box[3][3][9] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(row[i][num] || col[j][num] || sub_box[i/3][j/3][num]) return false;
                    row[i][num] = col[j][num] = sub_box[i/3][j/3][num] = true;
                }
            }
        }
        return true;
    }
};