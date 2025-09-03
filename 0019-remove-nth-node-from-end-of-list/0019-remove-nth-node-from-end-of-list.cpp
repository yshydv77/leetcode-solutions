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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == 0 && n == 1){return 0;}

        int len = 0;
        auto it = head;
        while(it){
            len++;
            it = it->next;
        }

        auto pos = len - n;
        it = head;
        for(int i = 0 ; i < pos-1 ; i++){
            it = it->next;

        }
        if(pos == 0){
            head = head->next;
            it->next = 0;
            delete it;
            return head;
        }
        auto current = (it->next);
        auto forward = current->next;
        it->next = forward;
        current->next = 0;
        delete(current);
        return head;
    }
};