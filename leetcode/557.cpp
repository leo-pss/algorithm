#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> split(string str){
        istringstream iss(str);
        string buffer;
        vector<string> result;
        
        while(getline(iss,buffer,' ')){
            result.push_back(buffer);
        }
        return result;
    }
    string reverseWords(string s) {
        vector<string> split_s = split(s);
        string answer;
        for(int i = 0; i < split_s.size(); i++){
            reverse(split_s[i].begin(), split_s[i].end());
            answer += split_s[i];
            if(i != split_s.size() - 1) answer += " ";
        }
        return answer;
    }
};