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
ListNode *deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* i = head;
    ListNode* j = head->next;

    while(j != nullptr && j->next != nullptr){
        
        while(j!= nullptr && j->val == i->val){
            
            j = j->next;

        }
        // j->val != i->val
        // mtlb bich mein repeated elements the
        i->next = j;
        i = j;
        if(j!=nullptr){
            j = j->next;
        }
            

    }

    // last node hogi 
    if(j!= nullptr && j->next == nullptr){
        if(i->val == j->val){
            i->next = nullptr;
        }

    }
    return head;

}
};