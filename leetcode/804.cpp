#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> trans;
        
        for(string word : words){
            string tmp = "";
            for(char c : word){
                tmp = tmp + morse[c - 'a'];
            }
            trans.insert(tmp);
        }
        return trans.size();
    }
};