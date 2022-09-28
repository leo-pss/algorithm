struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int solve(ListNode* prev, ListNode* head, int n){
        if(head == nullptr) return 0;
        int ret = solve(head, head->next, n);
        if(ret == n-1){
            prev->next = head->next;
        }
        return ret+1; 
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode;
        root->next = head; 
        solve(root, root->next, n);
        return root->next;
    }
};