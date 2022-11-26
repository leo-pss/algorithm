#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; });
        map<int, int> timeMap;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            auto it = timeMap.lower_bound(endTime[idx[i]]);
            if(it == timeMap.end()) answer = max(answer, profit[idx[i]]);
            else answer = max(answer, it->second + profit[idx[i]]);
            timeMap[startTime[idx[i]]] = answer;
        }
        return answer;
    }
};