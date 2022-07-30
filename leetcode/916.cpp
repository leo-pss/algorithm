#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> count_chr(string a){
        vector<int> ret(26, 0);
        for(char x : a) ret[x-'a']++;
        return ret;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> w2(26, 0);
        for(auto word2 : words2) {
            auto chr = count_chr(word2);
            for(int i = 0; i < 26; i++){
                w2[i] = max(w2[i], chr[i]);
            }
        }
        vector<string> answer;
        for(auto word : words1){
            int chk = 1;
            auto chr = count_chr(word);
            for(int i = 0; i < 26; i++){
                if(chr[i] < w2[i]) chk = 0;
            }
            if(chk == 1) answer.push_back(word);
        }
        return answer;
    }
};