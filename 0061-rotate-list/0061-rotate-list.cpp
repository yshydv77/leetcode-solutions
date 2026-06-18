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
ListNode* rotateRight(ListNode* head, int k) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  int n = 1;
  ListNode* temp = head;
  while (temp->next != nullptr) {
    n++;
    temp = temp->next;
  }

  k = k % n;
  if (k == 0) {
    return head;
  }

  ListNode* lastnode = temp;
  int value = n - k;
  temp = head;
  for (int i = 0; i < value - 1; i++) {
    temp = temp->next;
  }

  ListNode* nMinusKthNode = temp;
  ListNode* nMinusKPlus1thNode = temp->next;

  nMinusKthNode->next = nullptr;
  lastnode->next = head;
  head = nMinusKPlus1thNode;
  return head;
}

};