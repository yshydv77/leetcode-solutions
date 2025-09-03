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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        auto it = head;
        auto odd = new ListNode(-1);
        auto itOdd = odd;
        auto even = new ListNode(-1);
        auto itEven = even;
        auto position = 1;
        while(it){
           
            if(position & 1){//odd 
                itOdd->next = it;
                itOdd = itOdd->next;
            }
            else{
                itEven->next = it;
                itEven = itEven->next;
            }   
            it = it->next;
            position++;
        }

        itOdd->next = even->next;
        itEven->next = 0;
        return odd->next;

    }
};