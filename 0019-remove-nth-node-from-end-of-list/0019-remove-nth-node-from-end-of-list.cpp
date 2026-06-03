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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(head->next == nullptr && n == 1){
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    // create the gap between them
    while(fast != nullptr && fast->next!=nullptr && n--){
        fast = fast->next;
    }

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    if(n==1){
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else{
    ListNode* temp = slow->next;
    slow->next = temp->next;
    temp->next = nullptr;
    delete temp;
    }
    return head;

}
};