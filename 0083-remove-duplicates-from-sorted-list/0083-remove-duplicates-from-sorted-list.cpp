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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            // no node or either 1 node
            return head;
        }
        ListNode* previous = head;
        ListNode* current = head->next;
      
        while(current != NULL){
            if(current->val != previous->val){
                previous = previous->next;
                current = current->next;
            }
            else{
               previous->next = current->next;
               current->next = NULL;
               delete(current);
               current = previous->next;
            }
        }
        
        return head;
    }
};