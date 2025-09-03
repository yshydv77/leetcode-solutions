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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        auto it = head;
        while(it){
            N++;
            it = it->next;
        }

        int idealSize = N / k;
        int extraNodes = N % k;
        vector<ListNode*>ans(k,nullptr);
        it = head;
        for(int i = 0 ; i < k && it ; i++){
            ans[i] = it;
            int actualPartSize = idealSize + (extraNodes-- > 0 ? 1 : 0);

            for(int j = 0 ; j < actualPartSize - 1 ; j++){
                it = it->next;
            }
            auto remainingLL = it->next;
            it->next = 0;
            it = remainingLL;
        }
        return ans;

    }
};