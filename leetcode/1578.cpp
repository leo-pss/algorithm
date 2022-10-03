#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int answer = 0;
        int color_max = 0;
        int sum = 0;
        char prev = 'A';
        for(int i = 0; i < colors.size(); i++){
            if(prev != colors[i]){
                answer += (sum - color_max);
                sum = 0;
                color_max = 0;
            }
            sum += neededTime[i];
            color_max = max(color_max, neededTime[i]);
            prev = colors[i];
        }
        answer += (sum - color_max);
        return answer;
    }
};