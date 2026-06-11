class Solution {
public:
// 35 serach insert positon 
int searchInsert(vector<int>& nums, int target) {
  // search index sorted binary serach
  int low = 0;
  int high = nums.size()-1;
  int ans = -1;
  while (low<=high)
  {
    int mid = low + (high - low)/2;
    if(nums[mid] == target){
      ans = mid;
      break;
    }
    if(nums[mid] < target){
      low = mid+1;
    }
    else{
      ans = mid;
      high = mid-1;
    }
  }

  if(ans == -1){
    ans = nums.size();
  }
  return ans;
  
}
};