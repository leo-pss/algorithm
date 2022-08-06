#include <cmath>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int answer = 0;
        int possible_test = (minutesToTest / minutesToDie) + 1;
        while(pow(possible_test, answer) < buckets) answer++;
        return answer;
    }
};