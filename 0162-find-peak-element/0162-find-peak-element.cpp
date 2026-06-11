class Solution {
public:

int findPeakElement(vector<int>& nums) {
  if(nums.size() == 1){
    return 0;
  }
  int low = 0;
  int high = nums.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if(mid+1 < nums.size()){

    if (nums[mid] < nums[mid + 1]) {
      low = mid + 1;
    } else if (nums[mid] > nums[mid + 1]) {
      ans = mid;
      high = mid - 1;
    }

    }
    else{
      break;
    }
  }

  if(ans == -1){
    return nums.size()-1;
  }
  return ans;
}
};