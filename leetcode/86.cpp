#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> less;
        vector<int> greater;
        ListNode *prev;
        prev = head;
        while(prev != nullptr){
            if(prev->val < x) less.push_back(prev->val);
            else greater.push_back(prev->val);
            prev = prev -> next;
        }
        if(less.size() == 0){
            prev = head;
            for(int i = 0; i < greater.size(); i++){
                prev->val = greater[i];
                prev = prev->next;
            }
        }
        else{
            prev = head;
            for(int i = 0; i < less.size(); i++){
                prev->val = less[i];
                prev = prev->next;
            }
            for(int i = 0; i < greater.size(); i++){
                prev->val = greater[i];
                prev = prev->next;
            }
        }
        return head;
    }
};