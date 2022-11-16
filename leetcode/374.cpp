/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while(lo <= hi) {
            int p = lo + (hi - lo) / 3;
            int q = hi - (hi - lo) / 3;
            int res_p = guess(p);
            int res_q = guess(q);
            if(res_p == 0) return p;
            if(res_q == 0) return q;
            else if(res_p < 0) hi = p - 1;
            else if(res_q > 0) lo = q + 1;
            else {
                lo = p + 1;
                hi = q - 1;
            }
        }
        return -1;
    }
};