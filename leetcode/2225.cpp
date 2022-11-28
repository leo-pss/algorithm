#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> players;
        for(auto match : matches){
            int winner = match[0], loser = match[1];
            if(players.find(winner) == players.end()) players[winner] = 0;
            if(players.find(loser) == players.end()) players[loser] = 0;
            ++players[loser];
        }
        vector<vector<int>> answer(2, vector<int>());
        for(auto& it : players){
            if(it.second == 0) answer[0].push_back(it.first);
            else if(it.second == 1) answer[1].push_back(it.first);
        }
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};