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
  ListNode* temp = node;
  ListNode* next_node = temp->next;
  // now swap the value of next node in the temp 

  temp->val = next_node->val;
  temp->next = next_node->next;
  return ;
}
};