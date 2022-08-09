#include <vector>
#include <algorithm>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        vector<long long> d(n, 1);
        sort(arr.begin(), arr.end());
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++){
            umap.insert({arr[i], i});
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] != 0) continue;
                int k = arr[i] / arr[j];
                if(umap.count(k)){
                    d[i] = (d[i] + d[j] * d[umap[k]] % MOD) % MOD;
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < n; i++) answer = (answer + d[i]) % MOD;
        return answer;
    }
};