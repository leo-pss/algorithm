#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> buy(n, -1e9);
        vector<int> sell(n, 0);
        for(int i = 0; i < n; i++){
            int price = prices[i];
            for(int j = k; j > 0; j--){
                sell[j] = max(sell[j], buy[j] + price);
                buy[j] = max(buy[j], sell[j-1] - price);
            }
        }
        return sell[k];
    }
};