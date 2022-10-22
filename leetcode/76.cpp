#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        unordered_map<char, int> window_map;
        int min_len = 1e9;
        string answer;
        
        int len_t = t.size();
        for(char tmp : t) t_map[tmp]++;
        int l = 0, r = 0, cnt = 0;
        for(; r < s.size(); r++){
            char tmp = s[r];
            if(t_map.find(tmp) != t_map.end()){
                window_map[tmp]++;
                if(window_map[tmp] <= t_map[tmp]) cnt++;
            }
            if(cnt >= len_t){
                while(t_map.find(s[l]) == t_map.end() || window_map[s[l]] > t_map[s[l]]) {
                    window_map[s[l]]--;
                    l++;
                }
                if(min_len > r - l + 1){
                    min_len = r - l + 1;
                    answer = s.substr(l, min_len);
                }
            }
        }
        
        return answer;
    }
};