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
  void reverseLL(ListNode* head , int k ){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(k--){
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return;
  }
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode* prev_left = nullptr;
  ListNode* left = head;
  ListNode* res = nullptr;


  while (true) {
    // mujhe pair kitne hai ye nahi pata hai isliye liye infinite while loop use kar rahe hai 
    ListNode* right = left;
    for (int i = 0; i < k - 1; i++) {
      if (right == nullptr) {
        break;
      }
      right = right->next;
    }

    if(right != nullptr){
      ListNode* next_left = right->next;
      reverseLL(left , k );
      if(prev_left != nullptr){
        prev_left->next = right;
      }
      prev_left = left;
      if(res == nullptr){
        res = right;
      }

      left = next_left;
    } 
    else{
      if(prev_left != nullptr){
        prev_left ->next = left;
      }
      if(res == nullptr){
        res = left;
      }
      break;
    }
  }

  return res;
    }
};