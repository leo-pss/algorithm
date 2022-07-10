#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> pay(n, INF);
        pay[0] = cost[0]; pay[1] = cost[1];
        for(int i = 2; i < n; i++){
            pay[i] = min(pay[i], pay[i-1] + cost[i]);
            pay[i] = min(pay[i], pay[i-2] + cost[i]);
        }
        return min(pay[n-1], pay[n-2]);
    }
};