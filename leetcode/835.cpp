#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> one1, one2;
        int n = img1.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) one1.push_back(i * 100 + j);
                if(img2[i][j] == 1) one2.push_back(i * 100 + j);
            }
        }
        unordered_map<int, int> count;
        int answer = 0;
        for(int i : one1)
            for(int j : one2)
                count[i-j]++;
        for(auto cnt : count) answer = max(answer, cnt.second);
        
        return answer;                
    }
};