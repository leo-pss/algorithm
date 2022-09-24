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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum) ret.push_back({root->val});
            return ret;
        }
        vector<vector<int>> left = pathSum(root->left, targetSum - root->val);
        vector<vector<int>> right = pathSum(root->right, targetSum - root->val);
        for(auto l : left){
            vector<int> tmp;
            tmp.push_back(root->val);
            tmp.insert(tmp.end(), l.begin(), l.end());
            ret.push_back(tmp);
        }
        for(auto r : right){
            vector<int> tmp;
            tmp.push_back(root->val);
            tmp.insert(tmp.end(), r.begin(), r.end());
            ret.push_back(tmp);
        }
        return ret;
    }
};