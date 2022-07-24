#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int y = n-1, x = 0;
        bool answer = false;
        while(y>=0 && y<n && x>=0 && x<m){
            if(matrix[y][x] == target){
                answer = true;
                break;
            }
            else if(matrix[y][x] > target){
                y--;
            }
            else{
                x++;
            }
        }
        return answer;
    }
};