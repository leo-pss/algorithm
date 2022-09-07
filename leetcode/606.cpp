#include <string>

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
    string tree2str(TreeNode* root) {
        string s;
        if(root == nullptr) return s;
        s += to_string(root->val);
        
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        if(!left.empty()){
            s += "(";
            s += left;
            s += ")";
        }
        else if(!right.empty()){
            s += "()";
        }
        if(!right.empty()){
            s += "(";
            s += right;
            s += ")";
        }
        return s;
    }
};