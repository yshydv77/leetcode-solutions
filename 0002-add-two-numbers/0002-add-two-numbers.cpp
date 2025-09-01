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
    ListNode* reverseLL(ListNode*& head) {
        ListNode* current = head;
        ListNode* previous = NULL;
        while (current != NULL) {
            ListNode* forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }
    int getLength(ListNode*& head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* equaliser(ListNode*& temp, int diff) {
        temp = reverseLL(temp);
        while (diff--) {
            ListNode* newNode = new ListNode(0);
            newNode->next = temp;
            temp = newNode;
        }
        temp = reverseLL(temp);
        return temp;
    }
    void printLL(ListNode* &head){
        ListNode* temp = head;
        while(temp!= NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = getLength(l1);
        int length2 = getLength(l2);
        int diff = abs(length1 - length2);
        cout<<"Before Equalised "<<endl;
        cout<<"l1: " ;
        printLL(l1);
        cout<<"l2: " ;
        printLL(l2);
        if (length1 < length2) {
            l1 = equaliser(l1 , diff);
        } 
        else {
            l2 = equaliser(l2 , diff);
        }
        cout<<"After Equalised "<<endl;
        cout<<"l1: " ;
        printLL(l1);
        cout<<"l2: " ;
        printLL(l2);

        int carry = 0 ;
        ListNode* temp = NULL;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = NULL;
        while(temp1 != NULL && temp2 != NULL){
            int data1 = temp1->val;
            int data2 = temp2->val;
            int sum = data1 + data2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            if(temp == NULL && head == NULL){
                temp = newNode;
                head = temp;
            }
            else{
                temp->next = newNode;
                temp = newNode;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }
        return head;
    }
};