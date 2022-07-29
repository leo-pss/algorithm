#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int m = pattern.size();
        vector<int> ch(26, 0);
        vector<int> p(m, 0);
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            char s = pattern[i];
            if(ch[s-'a'] != 0){
                p[i] = ch[s-'a'];
            }
            else{
                ch[s-'a'] = ++cnt;
                p[i] = cnt;
            }
        }
        vector<string> answer;
        for(string word : words){
            vector<int> word_ch(26, 0);
            cnt = 0;
            int chk = 1;
            for(int i = 0; i < m; i++){
                char s = word[i];
                if(word_ch[s-'a'] != 0){
                    if(p[i] != word_ch[s-'a']){
                        chk = 0;
                        break;
                    }
                }
                else{
                    word_ch[s-'a'] = ++cnt;
                    if(p[i] != cnt){
                        chk = 0;
                        break;
                    }
                }
            }
            if(chk) answer.push_back(word);
        }
        return answer;
    }
};