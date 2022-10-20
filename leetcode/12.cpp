#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman1[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string roman10[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string roman100[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string roman1000[10] = {"","M","MM","MMM"};
        
        string answer = "";
        answer += roman1000[num/1000];
        answer += roman100[(num%1000)/100];
        answer += roman10[(num%100)/10];
        answer += roman1[num%10];
        return answer;
    }
};