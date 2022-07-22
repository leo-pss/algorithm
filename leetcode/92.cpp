struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *tmp = new ListNode(0);
        ListNode *prev = tmp;
        ListNode *curr;
        tmp->next = head;
        for(int i = 0; i < left - 1; i++){
            prev = prev->next; 
        }
        curr = prev->next;
        for(int i = 0; i < right - left; i++){
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return tmp->next;
    }
};