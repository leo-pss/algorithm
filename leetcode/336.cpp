#include <vector>
#include <string>

using namespace std;

struct TrieNode{
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> pindex;
};

class Solution {
    bool isPal(string &s, int l, int r){
        while(l < r && s[l] == s[r]) ++l, --r;
        return l >= r;
    }
    TrieNode root;
    void insert(string &s, int index){
        auto node = &root;
        for(int i = s.size() - 1; i >= 0; --i){
            int c = s[i] - 'a';
            if(!node->next[c]) node->next[c] = new TrieNode();
            if(isPal(s, 0, i)) node->pindex.push_back(index);
            node = node->next[c];
        }
        node->index = index;
        node->pindex.push_back(index);
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) insert(words[i], i);
        vector<vector<int>> answer;
        
        for(int i = 0; i < words.size(); ++i) {
            auto node = &root;
            auto s = words[i];
            for(int j = 0; j < s.size(); j++){
                if(node->index != -1 && node->index != i && isPal(s, j, s.size() - 1)) {
                    answer.push_back({i, node->index});
                }
                node = node->next[s[j]-'a'];
                if(!node) break;
            }
            if(node) {
                for(int j : node->pindex) {
                    if(i!=j) answer.push_back({i, j});
                }
            }
        }
        
        return answer;
    }
};