#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> uf;
    int find(int a){
        if(uf[a] == -1 || uf[a] == a) return a;
        return find(uf[a]);
    }
    bool equationsPossible(vector<string>& equations) {
        uf.resize(26);
        for(int i = 0; i < 26; i++) uf[i] = -1;
        for(string e : equations){
            int l = e[0] - 'a', r = e[3] - 'a';
            if(e[1] == '='){
                uf[find(l)] = find(r);
            }
        }
        for(string e : equations){
            int l = e[0] - 'a', r = e[3] - 'a';
            if(e[1] == '!'){
                if(find(l) == find(r)) return false;
            }
        }
        return true;
    }
};
