#include <string>
#include <vector>

using namespace std;

struct Trie {
    Trie* child[26] = {};
    string* word;
    void addWord(string& word) {
        Trie* cur = this;
        for(char c : word) {
            c -= 'a';
            if (cur->child[c] == nullptr) cur->child[c] = new Trie();
            cur = cur->child[c];
        }
        cur->word = &word;
    }
};

class Solution {
public:
    int n, m;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    vector<string> answer;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(); m = board[0].size();
        Trie root;
        for(string& word : words) root.addWord(word);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(board, i, j, &root);
            }
        }
        return answer;
    }
    void dfs(vector<vector<char>>& board, int y, int x, Trie* cur){
        if(y < 0 || y >= n || x < 0 || x >= m || board[y][x]=='#') return;
        if(cur->child[board[y][x] - 'a'] == nullptr) return;
        char c = board[y][x];
        cur = cur->child[c - 'a'];
        if(cur->word != nullptr){
            answer.push_back(*cur->word);
            cur->word = nullptr;
        }
        board[y][x] = '#';
        for(int i = 0; i < 4; i++) dfs(board, y+dy[i], x+dx[i], cur);
        board[y][x] = c;
    }
};