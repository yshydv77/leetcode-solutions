class Solution {
public:
  // kth largest max heap question
  int findKthLargest(vector<int> & nums, int k) {
 priority_queue<int,vector<int>, greater<int>>pq;
    // max heap 
    
    for (int i = 0 ;i < nums.size() ;i++)
    { 
      if(i<k){
        pq.push(nums[i]);
      }
      else{
        pq.push(nums[i]);
        pq.pop();
      }
    }
    // for(int i = k ;i < nums.size() ; i++){
    //   if(pq.top() < nums[i]){
    //     pq.pop();
    //     pq.push(nums[i]);
    //   }
    //   else if(pq.top() >= nums[i]){
    //     continue;
    //   }
    // }
    

    return pq.top();
    
    
    
    // priority_queue<int> pq;

    // for (auto& it : nums) {
    //   pq.push(it);
    // }
    // k--;
    // while (k--) {
    //   pq.pop();
    // }
    // return pq.top();
  }
};