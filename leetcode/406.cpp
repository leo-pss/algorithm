#include <vector>
#include <algorithm>
#define INF 1000001

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<int> check(n, INF);
        vector<vector<int>> answer(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++){
            int now = 0;
            int p = people[i][1];
            while(1){
                if(check[now]==INF && p==0){
                    check[now] = people[i][0];
                    answer[now] = people[i];
                    break;
                }
                if(check[now] >= people[i][0]) p--;
                now++;
            }
        }
        return answer;
    }
};
    