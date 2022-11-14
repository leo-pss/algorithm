#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:        
    unordered_map<int, int> parent;
    int cnt = 0;

    int find(int x) {
        if (!parent.count(x)){
            parent[x] = x;
            cnt++;
        }
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void uni(int x, int y) {
        x = find(x); y = find(y);
        if(x != y) {
            parent[x] = y;
            cnt--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], ~stones[i][1]);
        return stones.size() - cnt;
    }


};