#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_count;
        vector<int> answer;
        for(string word : words) word_count[word]++;
        int n = s.length();
        int word_num = words.size();
        int word_len = words[0].length();
        if(n == 0 || word_num == 0) return answer;
        for(int i = 0; i <= n - word_num * word_len; i++){
            unordered_map<string, int> tmp;
            int j = 0;
            while(j < word_num){
                string word = s.substr(i + j * word_len, word_len);
                if(word_count.find(word) != word_count.end()){
                    tmp[word]++;
                    if(word_count[word] < tmp[word]) break;
                }
                else break;
                j++;
            }
            if(j == word_num) answer.push_back(i);
        }
        return answer;
    }
};