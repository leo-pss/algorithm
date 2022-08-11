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
    bool solve(TreeNode* root, long min_val, long max_val){
        if(!root) return true;
        if(root->val <= min_val || root->val >= max_val) return false;
        return solve(root->left, min_val, root->val) && solve(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, (long)(-2147483649), (long)(2147483648));
    }
};