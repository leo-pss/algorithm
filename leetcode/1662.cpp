#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0, idx2 = 0;
        int cnt1 = 0, cnt2 = 0;
        
        while(idx1 < word1.size() && idx2 < word2.size()){
            if(word1[idx1][cnt1++] != word2[idx2][cnt2++]) return false;
            
            if(cnt1 >= word1[idx1].size()){
                idx1++;
                cnt1 = 0;
            }
            if(cnt2 >= word2[idx2].size()){
                idx2++;
                cnt2 = 0;
            }
        }
        return idx1 == word1.size() && idx2 == word2.size();
    }
};