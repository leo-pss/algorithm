#include <vector>

using namespace std;

class Solution {
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1,0,-1,0};
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, i, j, word, 0)) return true;
            }
        }      
        return false;
    }

    bool dfs(vector<vector<char>>& board, int y, int x, string& word, int idx){
        if(idx >= word.size()) return true;
        if(y<0 || x<0 || y>=board.size() || x>=board[0].size()) return false;
        if(board[y][x] != word[idx]) return false;
        bool ret = false;
        char tmp = board[y][x];
        board[y][x] = '*';
        for(int k = 0; k < 4; k++){
            ret |= dfs(board, y+dy[k], x+dx[k], word, idx+1);
        }
        board[y][x] = tmp;
        return ret;        
    }
};