#include <stack>
#include <vector>
#define INF 1000000001

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, INF);
        stack<int> s;
        
        if(n==1){
            answer[0] = -1;
            return answer;
        }
        for(int i = n*2-1; i>=0; --i){
            while(!s.empty() && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            if(s.empty()) answer[i%n] = -1;
            else answer[i%n] = nums[s.top()];
            s.push(i%n);
        }
        
        return answer;
    }
};