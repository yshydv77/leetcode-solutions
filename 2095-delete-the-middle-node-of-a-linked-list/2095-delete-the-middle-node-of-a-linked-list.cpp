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

const auto null = nullptr;
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == null || head->next == null){
            return null;
        }
        ListNode* slow =  head;
        ListNode* fast = head;
        ListNode* slow_prev = head;
        while(fast != null && fast->next != null){
            slow_prev = slow;
            slow =  slow->next;
            fast = fast->next->next;

        }

        slow_prev->next = slow->next;
        slow->next = null;
        delete slow;
        return head;
    }
};