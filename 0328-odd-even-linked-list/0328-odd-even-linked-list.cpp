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
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    int index = 1;
    ListNode *even = nullptr;
    ListNode *odd = nullptr;
    ListNode* e = even;
    ListNode* o = odd;
    ListNode *t = odd;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        ListNode* node = new ListNode(temp->val);
        if (even == nullptr && index % 2 == 0)
        {
            even = node;
            e = even;
        }
        else if (odd == nullptr && index % 2 != 0)
        {
            odd = node;
            o = odd;
        }
        else if(even != nullptr && index % 2 == 0){
            e->next = node;
            e = e->next;
        }
        else if(odd != nullptr && index % 2 != 0 ){
            o->next = node;
            o = o->next;
        }

        index++;
        temp = temp->next;

    }
    o->next = even;
    return odd;
}
};