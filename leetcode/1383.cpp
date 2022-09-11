#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {        
        long long answer = 0;
        long long sum = 0;
        
        if(k == 1){
            for(int i = 0; i < n; i++){
                answer = max(answer, (long long)speed[i] * efficiency[i]);
            }
            return answer;
        }
        
        vector<pair<int, int> > es(n);
        for(int i = 0; i < n; i++){
            es[i] = {efficiency[i], speed[i]};
        }
        sort(es.begin(), es.end());
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = n - 1; i >= 0; i--){
            if(pq.size() == k - 1) {
                answer = max(answer, (sum + es[i].second) * es[i].first);
                if(es[i].second > pq.top()){
                    sum -= pq.top();
                    sum += es[i].second;
                    pq.pop();
                    pq.push(es[i].second);
                }
            }
            else if(pq.size() < k - 1){
                sum += es[i].second;
                answer = max(answer, sum * es[i].first);
                pq.push(es[i].second);
            }            
        }
        
        return answer % 1000000007;
    }
};