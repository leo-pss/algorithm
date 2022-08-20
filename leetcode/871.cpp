#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int reach = startFuel;
        int answer = 0;
        int i = 0;
        while(reach < target){
            while(i < n && stations[i][0] <= reach){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            int move = pq.top(); pq.pop();
            reach += move;
            answer++;
        }
        return answer;
    }
};