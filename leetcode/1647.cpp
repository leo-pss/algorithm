#include <queue>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        vector<int> fre(26, 0);
        for(auto chr : s){
            fre[chr-'a']++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(fre[i]!=0) pq.push(fre[i]);
        }
        int prev = pq.top(); pq.pop();
        int answer = 0;
        while(!pq.empty()){
            int cur = pq.top(); pq.pop();
            if(prev==cur && prev>0){
                pq.push(cur-1);
                ++answer;
            }
            prev = cur;
        }
        return answer;
    }
};