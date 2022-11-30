#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        for(int num : arr) ++occ[num];
        unordered_set<int> count;
        for(auto& it : occ){
            if(count.find(it.second) != count.end()) return false;
            count.insert(it.second);
        }
        return true;
    }
};