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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* mid(ListNode* head){
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            if(slow != temp){
                temp = temp->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return temp;
    }
    ListNode* reverseLL( ListNode* current){
        ListNode* previous = NULL;
        while(current != NULL){
            ListNode* forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }
    void printLL(ListNode* head){
        ListNode* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        ListNode* slow = mid(head);
        
        ListNode* mid = slow->next;
       
        // cout<<"Printing the linked list before reversal "<<endl;
        // printLL(head);
        int length = getLength(head);
        ListNode* previous = NULL;
        if(length & 1 ){
            previous = reverseLL(mid->next);
        }
        else{
            previous = reverseLL(mid);
        }
        slow->next = previous;

        // cout<<"Printing the linked list after reversal "<<endl;
        printLL(head);

        ListNode* temp1 = head;
        // cout<<"value of temp1 is : "<<temp1->val<<endl;

        ListNode* temp2 = previous;
        // cout<<"value of temp2 is : "<<temp2->val<<endl;

        while(temp2!=NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;

        }

        return true;


    }
};