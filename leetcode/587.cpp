#include <vector>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int cross(vector<int>& B, vector<int>& A, vector<int>& T){
        return (T[1]-B[1])*(B[0]-A[0]) - (B[1]-A[1])*(T[0]-B[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        sort(trees.begin(), trees.end());
        deque<vector<int>> F;
        for (auto T : trees)
        {
            while (F.size() >= 2 && cross(F[F.size()-1],F[F.size()-2],T) < 0)
                F.pop_back();
            F.push_back(T);

            while (F.size() >= 2 && cross(F[0],F[1],T) > 0)
                F.pop_front();
            F.push_front(T);
        }
        
        set<vector<int>> unique(F.begin(), F.end());
        return vector<vector<int>>(unique.begin(), unique.end());
    }
};