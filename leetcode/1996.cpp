#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int max_d = 0;
        int answer = 0;
        for(int i = properties.size() - 1; i >= 0; i--){
            if(properties[i][1] < max_d) answer++;
            max_d = max(max_d, properties[i][1]);
        }
        return answer;
    }
};