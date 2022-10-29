#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> tmp(n);
        iota(tmp.begin(), tmp.end(), 0);
        sort(tmp.begin(), tmp.end(), 
             [&](int i, int j) { return growTime[i] > growTime[j]; });
        int answer = 0, sum = 0;
        for(int i : tmp){
            sum += plantTime[i];
            answer = max(answer, sum + growTime[i]);
        }
        return answer;
    }
};