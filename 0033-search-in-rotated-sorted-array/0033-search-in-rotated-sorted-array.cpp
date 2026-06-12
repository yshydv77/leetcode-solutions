class Solution {
public:

int search(vector<int>& nums, int target) {
  int n = nums.size();
  int low = 0 ;
  int high = n-1;
  while(low <= high){
    int mid = low + (high - low )/2;
    // part decide karna hai 
    if(nums[mid] > nums[n-1]){
      // part1 
      if(nums[mid] == target){
        return mid;
      }
      if(nums[mid] < target){
        low =  mid+1;
      }
      if(nums[mid] > target){
        if(target >= nums[0]){
          high = mid-1;
        }
        else{
          low = mid+1;
        }
      }
    }

    else{
      //part 2
      if(nums[mid] == target){
        return mid;
      }
      if(nums[mid] > target ){
        high = mid-1;
      }
      if(nums[mid] < target){
        if(target <= nums[n-1]){
          low = mid+1;
        }
        else{
          high = mid-1;
        }
      }
    }
  }
  return -1;
}
};