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
ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = nullptr;
    while (slow!=nullptr)
    {
        ListNode* node = new ListNode(slow->val);
        if(fast == nullptr){
            fast = node;
        }
        else{
            node->next = fast;
            fast = node;
        }
        slow = slow->next;
    }

    return fast;
    
}
};