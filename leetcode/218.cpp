#include <vector>
#include< algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> wall;
        for(auto b : buildings){
            wall.push_back({b[0], -b[2]});
            wall.push_back({b[1], b[2]});
        }
        sort(wall.begin(), wall.end());
        
        multiset<int> sky = {0};
        int top = 0;
        vector<vector<int>> answer;
        for(auto w : wall){
            if(w.second < 0) sky.insert(-w.second);
            else sky.erase(sky.find(w.second));
            if(top != *sky.rbegin()){
                top = *sky.rbegin();
                answer.push_back({w.first, top});
            }
        }
        return answer;
    }
};