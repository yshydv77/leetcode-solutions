class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
  // array subarray min len sum greater than target
  // sliding window ka question hoga length dynamic in nature hai 
  // variable sized sliding window ka question hai 
  int n = nums.size();
  
  int low = 0 ;
  int high = 0;
  int sum = 0;
  int ans = INT_MAX;


  for(high ; high < n ; high++){
    sum +=(nums[high]);
    while(sum >= target){
      int siz = high - low +1;
      ans = min(ans,siz);
      sum-=nums[low];
      low++;
    }

  }

  return (ans == INT_MAX)?0:ans;
}
};