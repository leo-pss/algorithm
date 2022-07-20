#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> chr(26);
        for(int i = 0; i < s.size(); i++){
            chr[s[i] - 'a'].push_back(i);
        }
        int answer = words.size();
        
        for(auto word : words){
            int prev = -1;
            for(char c : word){
                auto& chr_list = chr[c - 'a'];
                auto it = upper_bound(chr_list.begin(), chr_list.end(), prev);
                if(it == chr_list.end()){
                    --answer;
                    break;
                }
                prev = *it;
            }
        }
        return answer;
    }
};