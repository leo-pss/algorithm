#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> answer;
    vector<string> back;
    unordered_map<string, int> word_map;
    string begin_word;
    void dfs(string s){
        back.push_back(s);
        if(s == begin_word){
            vector<string> tmp = back;
            reverse(tmp.begin(), tmp.end());
            answer.push_back(tmp);
            back.pop_back();
            return;
        }
        int curr = word_map[s];
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            for(char j = 'a'; j <= 'z'; j++){
                s[i] = j;
                if(word_map.count(s) && word_map[s] == curr - 1){
                    dfs(s);
                }
            }
            s[i] = c;
        }
        back.pop_back();
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& word_list) {
        unordered_set<string> wordList(word_list.begin(), word_list.end());
        queue<string> Q;
        begin_word = beginWord;
        int k = beginWord.size();
        Q.push({beginWord});
        word_map[beginWord] = 0;
        while(!Q.empty()){
            int n = Q.size();
            while(n--){
                string word = Q.front(); Q.pop();
                int level = word_map[word] + 1;
                for(int i = 0; i < k; i++){
                    string tmp = word;
                    for(char c = 'a'; c <= 'z'; c++){
                        tmp[i] = c;
                        if(!word_map.count(tmp) && wordList.count(tmp)){
                            word_map[tmp] = level;
                            Q.push(tmp);
                        }
                    }
                }
            }
        }
        if(word_map.count(endWord)){
            dfs(endWord);
        }

        return answer;
    }
};