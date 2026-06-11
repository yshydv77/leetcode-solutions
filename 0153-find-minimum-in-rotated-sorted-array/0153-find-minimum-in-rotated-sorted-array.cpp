class Solution {
public:
int findMin(vector<int>& nums) {
  int n = nums.size();
  int low = 0;
  int high = n-1;
  int ans = -1;
  while(low <= high){
    int mid = low + (high - low)/2;
    // ab pata karna hai ki part 1 hai yaa  phir part 2 hai 
    if(nums[mid] > nums[n-1]){
      // part2 
      low = mid+1;
    }
    else{
      ans = mid;
      high = mid-1;
    }
  }

  if(ans == -1){
    ans = nums[0];
  }
  else{
    ans = nums[ans];
  }
  return ans;
}
};