#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> llist;
        while(head != nullptr){
            llist.push_back(head->val);
            head = head->next;
        }
        int n = llist.size(); 
        for(int i = 0; i < n / 2; i++){
            if(llist[i] != llist[n-1-i]) return false;
        }
        return true;
    }
};