#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        vector<pair<int,char>> o;
        for(auto& it : freq) o.push_back({-it.second, it.first});
        sort(o.begin(), o.end());
        string answer;
        for(auto c : o){
            for(int i = 0; i < -c.first; i++) answer += c.second;
        }
        return answer;
    }
};