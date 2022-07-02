#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long max_h = 0, max_w = 0;
        for(int i = 0; i < horizontalCuts.size() - 1; i++){
            max_h = max(max_h, (long long)(horizontalCuts[i+1] - horizontalCuts[i]));
        }
        for(int i = 0; i < verticalCuts.size() - 1; i++){                
            max_w = max(max_w, (long long)(verticalCuts[i+1] - verticalCuts[i]));
        }
        return (max_h * max_w) % (1000000007);
    }
};