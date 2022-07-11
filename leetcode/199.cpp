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
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(root == nullptr) return answer;
        answer.push_back(root->val);        
        auto left_answer = rightSideView(root->left);
        auto right_answer = rightSideView(root->right);
        for(int t : right_answer) answer.push_back(t);
        if(left_answer.size() > right_answer.size()){
            for(int i = right_answer.size(); i < left_answer.size(); i++)             {
                answer.push_back(left_answer[i]);
            }
        }
        return answer;
    }
};