#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chr(26, 0);
        for(char c : s){
            chr[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if(chr[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};