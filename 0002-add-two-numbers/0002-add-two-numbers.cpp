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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode(-1);
        auto it = ans;

        int carry = 0;

        // agar while loop mein tum l1 likh do toh jab bhi vo not null hoga tab vo while loop execute hoga otherwise null hone par vo execute nahi hoga
        // kisi bhi pointer null se point karna hai toh usko NULL ese na likhte hue agar aap 0 se bhi intialise karva skate hai 
        while(l1 || l2 || carry){//iterate tab tak jab tak l1 is not null or l2 is not null or carry is not zero 
            int data1 = l1 ? l1->val : 0;
            int data2 = l2 ? l2->val : 0;
            int sum = data1 + data2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            it->next = new ListNode (digit);
            it = it->next;

            l1 = l1 ? l1->next : 0; // ye intelligent practice hai ki aap phele hi check kar le ki l1 null toh nahi hai agar nahi hai toh hi uske next par jaye 
            // better to use this shorthand notation avoid using that big if statements for checking that li is null or not
            l2 = l2 ? l2->next : 0;

        }

        return ans->next;
    }
};
