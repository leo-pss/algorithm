#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> check(n, 0);
        vector<int> d(n, 0); 
        int cnt = 0;
        vector<pair<int,int>> dom;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'L') dom.push_back({i, -1});
            else if(dominoes[i] == 'R') dom.push_back({i, 1});
        }
        while(cnt < n && dom.size() != 0){
            vector<pair<int,int>> tmp;
            for(auto t : dom){
                check[t.first] = 1;
            }
            for(auto t : dom){
                d[t.first] += t.second;
                if(t.first + t.second < 0 || t.first + t.second >= n) continue;
                if(check[t.first + t.second]) continue;
                tmp.push_back({t.first+t.second, t.second});
                cnt++;
            }
            dom.clear();
            dom = tmp;
        }
        string answer;
        for(int i = 0; i < n; i++){
            if(d[i] == -1) answer += 'L';
            else if(d[i] == 0) answer += '.';
            else answer += 'R';
        }
        
        return answer;
    }
};