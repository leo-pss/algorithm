#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> answer;
    void solve(Node* root, int level) {
        if(answer.size() <= level){
            answer.push_back(vector<int>());
        }
        answer[level].push_back(root->val);
        for(Node* child : root->children){
            solve(child, level + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return answer;
        solve(root, 0);
        return answer;
    }
};