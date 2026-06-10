class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
  int low = 0 ;
  int high = nums.size()-1;
  int starting = -1;
  int ending = -1;
  while(low<=high){
    int mid = low + (high - low)/2;
    if(nums[mid] == target){
      starting = mid;
      high = mid-1;
    }
    else if(nums[mid] < target){
      low = mid+1;
    }
    else {
      high = mid-1;
    }
  }

  vector<int>ans;
  ans.push_back(starting);
  low = 0 ;
  high = nums.size()-1;
  while(low<=high){
    int mid = low + (high - low)/2;
    if(nums[mid] == target){
      ending = mid;
      low = mid+1;
    }
    else if(nums[mid] < target){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }

  ans.push_back(ending);
  return ans;
}
};