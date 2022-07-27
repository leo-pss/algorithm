#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* rright(TreeNode* root){
        if(root->right == NULL) return root;
        return rright(root->right);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* next_r;
        TreeNode* rr;
        
        while(root != NULL) {
            if(root -> left){
                rr = rright(root->left);
                next_r = root->right;
                root->right = root->left;
                root->left = NULL;
                rr->right = next_r;
            }
            root = root->right;
        }
    }
};