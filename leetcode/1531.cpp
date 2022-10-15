#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    const static int N = 127;
    int d[N][N];
    string str;
    int n;    
    
    int num_len(int num){
        if(num == 1) return 0;
        else if(num < 10) return 1;
        else if(num < 100) return 2;
        else return 3;
    }
    
    int solve(int l, int k){
        if(k < 0) return N;
        if(l >= n || n <= l + k) return 0;
        
        int& ret = d[l][k];
        if(ret != -1) return ret;
        ret = N;
        
        int chr_cnt[26] = {0};
        int max_chr = 0;
        for(int j = l; j < n; j++){
            max_chr = max(max_chr, ++chr_cnt[str[j] - 'a']);
            ret = min(ret, 1 + num_len(max_chr) + solve(j+1, k - (j + 1 - l - max_chr)));
        }
        return ret;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(d, -1, sizeof(d));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};