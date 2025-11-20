class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int rightSum = accumulate(nums.begin() , nums.end() , 0);
        int leftSum = 0;
        for(int i = 0 ;i < n ; i++){
          if(leftSum == (rightSum - nums[i])){
            ans = i;
            break;
          }
          leftSum += nums[i];
          rightSum -= nums[i];
        }

        return ans;
    }
};