#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> d(n+1, 10001);
        d[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sqrt(i); j++){
                d[i] = min(d[i], d[i - j*j] + 1);
            }
        }
        return d[n];
    }
};