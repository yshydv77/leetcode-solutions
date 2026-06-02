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
        if(head->next == nullptr && n == 1){
            return nullptr;
        }
        int sz = 0 ;

        ListNode* temp = head;
        while(temp!=nullptr){
            sz++;
            temp=temp->next;
        }
        temp =  head;


        int pos = sz - n;
        // if(pos == 0){
        //     ListNode* t = head;
        //     head = head->next;
        //     t->next = nullptr;
        // }
        for(int i = 0 ; i < pos-1; i++){
            temp=temp->next;
        }

        if(temp->next->next == nullptr && pos != 0){
            //last node ko delete karna tha
            temp->next = nullptr;
        }
        else if(pos != 0) {
            temp->next = temp->next->next;
        }
        else{
            ListNode* t = head;
            head = head->next;
            t->next = nullptr;
        }
        return head;
    }
};