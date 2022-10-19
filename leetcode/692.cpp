#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_map;
        for(string word : words) word_map[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string,int>>, Comp> pq;
        for(auto w : word_map){
            pq.emplace(w.first, w.second);
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> answer;
        while(!pq.empty()){
            answer.push_back(pq.top().first);
            pq.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
private:
    struct Comp {
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        }
    };
};