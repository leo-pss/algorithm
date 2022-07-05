#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num : nums){
            uset.insert(num);
        }
        
        int answer = 0;
        
        for(int num : uset){
            if(uset.find(num-1) == uset.end()){
                int cur = num;
                int cnt = 1;
                while(uset.find(cur+1)!=uset.end()){
                    ++cur;
                    ++cnt;
                }
                answer = max(answer, cnt);
            }
        }
        
        return answer;
    }
};