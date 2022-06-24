#include <algorithm>
#include <vector>
#include <set>
#define INF 1e9

using namespace std;

bool compare(const vector<int>&a, const vector<int>&b){
    return a[1] > b[1];
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int q = queries.size();
        vector<int> answer(q);
        
        for(int i = 0; i < q; i++){
            queries[i].push_back(i);
        }
        sort(rooms.begin(), rooms.end(), compare);
        sort(queries.begin(), queries.end(), compare);
        
        int room_idx = 0;
        
        set<int> room_ids;
        for(auto query : queries){
            while(room_idx < n && rooms[room_idx][1] >= query[1]){
                room_ids.insert(rooms[room_idx][0]);
                room_idx++;
            }
            if(room_ids.empty()){
                answer[query[2]] = -1;
                continue;
            }
            
            auto iter = room_ids.upper_bound(query[0]);
            
            int answer_id;
            if(iter == room_ids.begin()){
                answer_id = *iter; 
            }
            else{
                int right_val = iter == room_ids.end() ? INF : *iter;
                int left_val = *prev(iter);
                answer_id = abs(left_val - query[0]) <= abs(right_val - query[0]) ? left_val : right_val;
            }
            answer[query[2]] = answer_id;
        }
        
        return answer;
    }
};