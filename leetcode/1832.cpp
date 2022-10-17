#include <string>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int alpha_count[26] = {0};
        for(char s : sentence) alpha_count[s-'a']++;
        for(int i = 0; i < 26; i++) if(alpha_count[i] == 0) return false;
        return true;
    }
};