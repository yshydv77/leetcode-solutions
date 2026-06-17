/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  using ll = long long;
public:
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  ListNode* tempA = headA;
  ListNode* tempB = headB;
  ll m = 0 ;
  ll n = 0;
  while (tempA != nullptr)
  {
    m++;
    tempA = tempA->next;
  }
  while (tempB != nullptr)
  {
    n++;
    tempB = tempB->next;
  }
  tempA = headA;
  tempB = headB;
  ll diff = abs(m-n);
  if(m > n){
    while (diff--)
    {
      tempA = tempA->next;
    }
    
  }
  else if(n > m){
    while (diff--)
    {
      tempB = tempB->next;
    }
    
  }

  while (tempA != nullptr && tempB != nullptr)
  {
    if(tempA == tempB){
      return tempA;
    }
    tempA = tempA->next;
    tempB = tempB->next;
  }

  return nullptr;
  
  
  

}
};