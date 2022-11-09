#include <stack>
#include <algorithm>

using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> S;
    StockSpanner() {
        
    }
    int next(int price) {
        int ans = 1;
        while (!S.empty() && S.top().first <= price) {
            ans += S.top().second;
            S.pop();
        }
        S.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */