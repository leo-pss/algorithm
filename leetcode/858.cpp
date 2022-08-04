#include <algorithm>

using namespace std;

class Solution {
public:
    int gcd(int p, int q){
        if(q == 0) return p;
        if(p < q) swap(p, q);
        return gcd(q, p%q);
    }
    int mirrorReflection(int p, int q) {
        int r = gcd(p, q);
        int p_cnt = p / r;
        int q_cnt = q / r;
        if(q_cnt % 2 == 1){
            if(p_cnt % 2 == 0) return 2;
            else return 1;
        }
        else{
            return 0;
        }
    }
};