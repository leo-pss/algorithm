#include <vector>

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
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        elements.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = elements.size() - 1;
        while(l < r){
            if(elements[l] + elements[r] == k) return true;
            else{
                if(elements[l] + elements[r] < k) l++;
                else r--;
            }
        }
        return false;
    }
private:
    vector<int> elements;
};