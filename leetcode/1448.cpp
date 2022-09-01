#include <algorithm>

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
    int solve(TreeNode* curr, int max_val){
        int ret = 0;
        if(curr == NULL) return ret;
        if(curr->val >= max_val) ret++;
        max_val = max(curr->val, max_val);
        ret += solve(curr->left, max_val);
        ret += solve(curr->right, max_val);
        
        return ret;
    }
    int goodNodes(TreeNode* root) {
        int answer = 1;
        answer += solve(root->left, root->val);
        answer += solve(root->right, root->val);
        
        return answer;
    }
};