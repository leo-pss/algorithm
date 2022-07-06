#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int answer = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0) sum += customers[i];
        }
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1) sum += customers[i];
        }
        answer = sum;
        for(int i = 1; i <= n - minutes; i++){
            if(grumpy[i-1] == 1) sum -= customers[i-1];
            if(grumpy[i+minutes-1] == 1) sum += customers[i+minutes-1];
            answer = max(answer, sum);
        }
        return answer;
    }
};