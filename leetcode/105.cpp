
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
#include <vector>

using namespace std;
class Solution {
public:
    TreeNode* solve(int pre_left, int in_left, int in_right, vector<int>& preorder, vector<int>& inorder){
        if(pre_left >= preorder.size()) return nullptr;
        if(in_left > in_right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pre_left]);
        int root_index;
        for(int i = in_left; i <= in_right; i++){
            if(inorder[i] == preorder[pre_left]) {
                root_index = i;   
                break;
            }
        }
        root->left = solve(pre_left+1, in_left, root_index-1, preorder, inorder);
        root->right = solve(pre_left+root_index-in_left+1, root_index+1, in_right, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0, 0, inorder.size()-1, preorder, inorder);
    }
};