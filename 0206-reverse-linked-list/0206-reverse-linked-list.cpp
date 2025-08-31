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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
       else{
        ListNode* temp = head;
        ListNode* head1 = new ListNode(temp->val);
        temp = temp->next;
        while(temp != NULL){
            ListNode* newNode = new ListNode (temp->val);
            newNode->next = head1;
            head1 = newNode;
            temp = temp->next;
        }
        return head1;
       }
       return nullptr;
    }
};