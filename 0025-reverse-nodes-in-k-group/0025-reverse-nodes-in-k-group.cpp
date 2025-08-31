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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }
        if(count == k){

            ListNode* previous = NULL;
            ListNode* current = head;
            ListNode* forward = NULL;
            // reverse karva sakte hai 
            int i = 0;
            while(i<k){
                forward = current->next;
                current->next = previous;
                previous = current;
                current = forward;
                i++;
            }
            ListNode* recKaHead = reverseKGroup(forward , k);
            head->next = recKaHead;
            return previous;
        }
        else{   
        return head;
        }
        return nullptr;
    }
};