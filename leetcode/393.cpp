#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 6) count = 1;
                else if ((c >> 4) == 14) count = 2;
                else if ((c >> 3) == 30) count = 3;
                else if ((c >> 7)) return false;
            } 
            else {
                if ((c >> 6) != 2) return false;
                count--;
            }
        }
        return count == 0;
    }
};