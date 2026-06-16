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

ListNode* partition(ListNode* head, int x) {
  if(head == nullptr || head->next == nullptr){
    return head;
  }

  ListNode* temp = head;
  ListNode* less_x = nullptr;
  ListNode* greater_x = nullptr;  // greater and equal to x
  ListNode* h = nullptr;
  ListNode* g = nullptr;
  while (temp != nullptr) {
    ListNode* node = new ListNode(temp->val);
    if (temp->val < x) {
      if (less_x == nullptr) {
        less_x = node;
        h = less_x;
      } else {
        less_x->next = node;
        less_x = node;
      }
    } else if (temp->val >= x) {
      if (greater_x == nullptr) {
        greater_x = node;
        g = greater_x;
      } else {
        greater_x->next = node;
        greater_x = node;
      }
    }
    temp = temp->next;
  }
  if(h == nullptr){
    return g;
  }
  else {
    less_x->next = g;
  }
  return h;
}
};