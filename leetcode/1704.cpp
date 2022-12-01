#include <string>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size()/2; i++){
            char tmp = tolower(s[i]);
            if(tmp=='a'||tmp=='e'||tmp=='i'||tmp=='o'||tmp=='u') cnt++;
        }
        for(int i = s.size()/2; i < s.size(); i++){
            char tmp = tolower(s[i]);
            if(tmp=='a'||tmp=='e'||tmp=='i'||tmp=='o'||tmp=='u') cnt--;
        }
        return cnt == 0;
    }
};