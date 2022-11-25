#include <vector>
#include <stack>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {    
        int n = arr.size();

        vector<int> left(n,-1), right(n,n);
        stack<int> S;
        for(int i = 0; i < n; i++)
        {
            while(S.size() && arr[i] < arr[S.top()]) S.pop();
            if(S.size()) left[i] = i - S.top();
            else left[i] = i+1;
            S.push(i);
        }    
        while(S.size()) S.pop();
        for(int i = n - 1; i >= 0; i--)
        {
            while(S.size() && arr[i] <= arr[S.top()]) S.pop();
            if(S.size()) right[i] = S.top() - i;
            else right[i] = n - i;
            S.push(i);
        }
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            long long tmp = (left[i] * right[i]) % MOD;
            tmp = (tmp * arr[i]) % MOD;
            answer = (answer + tmp) % MOD;
        }
        return answer;
    }
};