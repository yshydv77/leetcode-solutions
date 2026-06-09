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
ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (head->next == nullptr || left == right) {
    return head;
  }

  ListNode* temp = head;
  ListNode* before = nullptr;

  int index = 1;
  for (index; index < left; index++) {
    before = temp;
    temp = temp->next;
  }

  int times = right - left + 1;
  ListNode* prev = nullptr;
  ListNode* curr = temp;

  while (times--) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  temp->next = curr;
  if (before != nullptr) {
    before->next = prev;
    return head;
  }
  return prev;
}
};