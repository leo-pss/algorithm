#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> anagram;
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            anagram[tmp].push_back(str);
        }
        for(auto it : anagram){
            answer.push_back(it.second);
        }
        return answer;
    }
};