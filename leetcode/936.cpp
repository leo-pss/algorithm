#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> ans;
        while(1){
            bool is_matched = false;
            for(int i = 0; i <= n - m; i++){
                bool check = true;
                int cnt = 0;
                for(int j = 0; j < m; j++){
                    if(target[i+j] == '.') cnt++;
                    else if(stamp[j] != target[i+j]){
                        check = false;
                        break;
                    }
                }
                if(check && cnt < m){
                    is_matched = true;
                    ans.push_back(i);
                    for(int j = 0; j < m; j++) target[i+j]='.';
                }
            }
            if(!is_matched) break;
        }
        for(char t : target){
            if(t != '.') return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};