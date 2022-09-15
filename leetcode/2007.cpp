#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        queue<int> d;
        vector<int> answer;
        
        sort(changed.begin(), changed.end());
        for(int c : changed) {
            if(d.empty()){
                answer.push_back(c);
                d.push(c * 2);
            }
            else if(d.front() != c) {
                answer.push_back(c);
                d.push(c * 2);
            }
            else{
                d.pop();
            }
        }
        if(d.empty()) return answer;
        else return vector<int>();
    }
};
