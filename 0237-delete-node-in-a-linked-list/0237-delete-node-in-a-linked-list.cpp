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
    void deleteNode(ListNode* node) {
        ListNode* current = node;
        ListNode* forward = node->next;
        current->val = forward->val;
        current->next = forward->next;
        forward->next = NULL;
        
    }
};