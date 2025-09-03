/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    auto itA = headA;
    auto itB = headB;
    
    while (itA != itB) {
        itA = (itA == nullptr) ? headB : itA->next;
        itB = (itB == nullptr) ? headA : itB->next;
    }
    return itA;  // could be intersection node or nullptr if no intersection
}

};