#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int score[n];
        priority_queue<pair<int, int> > pq;
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().second < i-k){
                pq.pop();
            }
            score[i] = nums[i] + (pq.empty() ? 0 : pq.top().first);
            pq.push({score[i], i});
        }
        return score[n-1];
    }
};