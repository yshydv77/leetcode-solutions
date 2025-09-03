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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* sHead = new ListNode (-1);
        ListNode* gHead = new ListNode (-1);

        ListNode* s = sHead;
        ListNode* g = gHead;

        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val < x){
                if(sHead->val == -1){sHead->val = temp->val;}
                else{

                    ListNode* newNode = new ListNode(temp->val);
                    s->next = newNode;
                    s = newNode;  
                }
            }
            else if(temp->val >= x){
                if(gHead->val == -1){gHead->val = temp->val;}
                else{
                    ListNode* newNode = new ListNode(temp->val);
                    g->next = newNode;
                    g = newNode;
                }
            }
           
            temp = temp->next;
        }
        if(sHead->val == -1){
            return gHead;
        }
        else if(gHead->val == -1){
            return sHead;
        }
        s->next = gHead;
        return sHead;

    }
};