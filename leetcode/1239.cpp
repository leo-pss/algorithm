#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int answer = 0;
        
        vector<bitset<26>> unique;
        for(string s : arr){
            bitset<26> tmp;
            for(char c : s) tmp.set(c - 'a');
            if(tmp.count() == s.size()) unique.push_back(tmp);
        }
        vector<bitset<26>> d = {bitset<26>()};
        for(auto& u : unique){
            for(int i = d.size() - 1; i >= 0; i--){
                if((d[i] & u).none()){
                    d.push_back(d[i] | u);
                    answer = max(answer, (int)(d[i].count() + u.count()));
                }
            }
        }
        return answer;
    }
};