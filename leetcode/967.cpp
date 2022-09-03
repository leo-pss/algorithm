#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<int> ans;
    void solve(int n, int curr, int len, int k) {
        if(len == n){
            ans.insert(curr);
            return;
        }
        int tmp = curr;
        int prev = curr % 10;
        if(prev + k < 10){
            tmp *= 10;
            tmp += (prev + k);
            solve(n, tmp, len + 1, k);
        }
        if(prev - k >= 0){
            curr *= 10;
            curr += (prev - k);
            solve(n, curr, len +  1, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) solve(n, i, 1, k);
        return vector<int>(ans.begin(), ans.end());
    }
};