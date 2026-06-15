class Solution {
public:
// kth largest max heap question
int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int>pq;

  for (auto& it : nums) {
    pq.push(it);
  }
  k--;
  while (k--)
  {
    pq.pop();
  }
  return pq.top();

}
};