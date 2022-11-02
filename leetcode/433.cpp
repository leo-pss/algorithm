#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> Q;
        unordered_set<string> visited;
        
        Q.push(start);
        visited.insert(start);
        
        int cnt = 0;
        while(!Q.empty()){
            int q_size = Q.size();
            for(int i = 0; i < q_size; i++){
                string now = Q.front(); Q.pop();
                if(now == end) return cnt;
                
                for(char c : "ACGT"){
                    for(int j = 0; j < now.size(); j++){
                        string tmp = now; tmp[j] = c;
                        if(!visited.count(tmp) && find(bank.begin(), bank.end(), tmp) != bank.end()) {
                            Q.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};