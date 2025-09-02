/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        // detect a loop wali method use karlo to find where slow and fast is equal
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
                if(slow == fast){
                    break;
                }
            }
        }
        fast = head;
        while(fast != slow && fast != NULL && slow != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};