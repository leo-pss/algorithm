#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> split_s;
        stringstream ss(s);
        string buffer;
        while(ss >> buffer){
            split_s.push_back(buffer);
        }
        string answer;
        for(int i = split_s.size() - 1; i >= 0 ; --i){
            if(i != split_s.size() - 1) answer += " ";
            answer += split_s[i];
        }
        return answer;
    }
};