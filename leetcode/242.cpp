#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> eng_s(26, 0);
        vector<int> eng_t(26, 0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            eng_s[s[i] - 'a']++;
            eng_t[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(eng_s[i] != eng_t[i]) return false;
        }
        return true;
    }
};