/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) return answer;
        vector<int> r(1, root->val);
        answer.push_back(r);
        
        auto tmp1 = levelOrder(root->left);
        auto tmp2 = levelOrder(root->right);
        int height = max(tmp1.size(), tmp2.size());
        for(int i = 0; i < height; i++){
            vector<int> tmp;
            if(i < tmp1.size())
                for(int t : tmp1[i]) tmp.push_back(t);
            if(i < tmp2.size())
                for(int t : tmp2[i]) tmp.push_back(t);
            answer.push_back(tmp);
        }
        return answer;
    }
};