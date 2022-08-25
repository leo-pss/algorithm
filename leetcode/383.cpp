#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chr(26, 0);
        for(char m : magazine) chr[m - 'a']++;
        for(char r : ransomNote){
            if(chr[r - 'a'] == 0) return false;
            chr[r - 'a']--;
        }
        return true;
    }
};