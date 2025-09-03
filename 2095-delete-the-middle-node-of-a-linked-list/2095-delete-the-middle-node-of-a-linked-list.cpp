/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == 0 || head->next == 0){
            return 0;
        }
        if(head->next->next == 0){
            head->next = 0;
            return head;
        }
        auto slow = head;
        auto fast = head;
        while(fast && fast->next){
            // fast and fast->next if they are non null then it is true oterwise false
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        auto forward = slow->next;
        slow->val = (forward->val);
        slow->next = forward->next;
        forward->next = 0;
        delete forward;
        return head;

    }
};