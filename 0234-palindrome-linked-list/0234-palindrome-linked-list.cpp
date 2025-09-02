/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* mid(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode* previous = NULL;
        while(current != NULL){
            ListNode* forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        int len = getLength(head);
        ListNode* m = mid(head);
        if(len & 1){// odd length ki linked list hai 
            m = m->next;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = reverse(m);

        while(temp2 != NULL){
            if(temp1->val !=  temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;

    }
};