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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1  && !list2) return 0;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;
        auto head = new ListNode(-1);
        auto temp = head;
        auto temp1 = list1;
        auto temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            else if(temp1->val > temp2->val){
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
            else{
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }
        while(temp1){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2){
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }

        return head->next;
    }
};