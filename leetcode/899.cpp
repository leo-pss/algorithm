#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        int n = s.size();
        string origin = s;
        s += s;
        for(int i = 0; i < n; i++){
            if(s.substr(i, n) < origin) origin = s.substr(i, n);
        }
        return origin;
    }
};