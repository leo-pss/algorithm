#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    multimap<int, pair<int, int>> m;
    void dfs(TreeNode* parent, int row, int col) {
        if(parent == NULL) return;
        m.insert({col, {row, parent->val}});
        dfs(parent->left, row+1, col-1);
        dfs(parent->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> answer;
        int prev = -1001;
        vector<pair<int,int>> tmp;
        vector<int> tmp2;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(prev != -1001 && prev != it->first){
                sort(tmp.begin(), tmp.end());
                for(auto t : tmp) tmp2.push_back(t.second);
                answer.push_back(tmp2);
                tmp.clear();
                tmp2.clear();
            }
            tmp.push_back(it->second);
            prev = it->first;
        }
        sort(tmp.begin(), tmp.end());
        for(auto t : tmp) tmp2.push_back(t.second);
        answer.push_back(tmp2);
        return answer;
    }
};