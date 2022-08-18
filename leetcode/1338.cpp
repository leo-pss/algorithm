#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int a : arr) count[a]++;
        vector<int> tmp;
        for(auto c : count){
            tmp.push_back(c.second);
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        int s = (arr.size() + 1) / 2;
        int sum = 0;
        int answer = 0;
        for(auto t : tmp){
            sum += t;
            answer++;
            if(sum >= s) break;
        }
        return answer;
    }
};