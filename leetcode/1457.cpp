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
    int solve(TreeNode* root, vector<int> digit) {
        if(root == nullptr) return 0;
        
        digit[root->val]++;
        if(root->left == nullptr && root->right == nullptr) {
            int cnt = 0;
            for(int i = 0; i < 10; i++){
                if(digit[i] % 2 == 1) cnt++;
            }
            return cnt <= 1 ? 1 : 0;
        }
        return solve(root->left, digit) + solve(root->right, digit);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digit(10, 0);
        return solve(root, digit);
    }
};