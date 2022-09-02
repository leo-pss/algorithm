#include <vector>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            vector<TreeNode*> level;
            while(!Q.empty()){
                auto tmp = Q.front(); Q.pop();
                level.push_back(tmp);
            }
            double sum = 0;
            for(auto tmp : level){
                if(tmp->left != NULL) Q.push(tmp->left);
                if(tmp->right != NULL) Q.push(tmp->right);
                sum += tmp->val;
            }
            answer.push_back(sum / level.size());
        }
        return answer;
    }
};