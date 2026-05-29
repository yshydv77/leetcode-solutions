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
    
ListNode *detectCycle(ListNode *head)
{
    // return the starting point of the cycle
    // ll starting point of the cycle 
    // slow and fast pointer ka question ha 
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!= NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // meeting point par mil gaye hai 
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return NULL;
}
};