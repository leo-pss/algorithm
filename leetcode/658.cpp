#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> tmp;
        for(int a : arr){
            tmp.push_back({abs(a-x), a});
        }
        sort(tmp.begin(), tmp.end());
        vector<int> answer;
        while(k--){
            answer.push_back(tmp[k].second);
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};