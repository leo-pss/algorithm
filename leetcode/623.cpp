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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return root;
        if(depth == 2){
            TreeNode* tmp_l = new TreeNode;
            TreeNode* tmp_r = new TreeNode;
            tmp_l->val = val;
            tmp_r->val = val;
            tmp_l->left = root->left;
            tmp_r->right = root->right;
            root->left = tmp_l;
            root->right = tmp_r;
            return root;
        }
        else if(depth == 1){
            TreeNode* tmp = new TreeNode;
            tmp->val = val;
            tmp->left = root;
            return tmp;
        }
        else{
            addOneRow(root->left, val, depth-1);
            addOneRow(root->right, val, depth-1);
            return root;
        }
    }
};