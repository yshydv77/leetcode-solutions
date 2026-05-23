class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin() , nums.end());

      int resultSum = 0 ;
      int maxDiff = INT_MAX;

      for(int i = 0 ; i < n-2 ;i++){
        int left = i+1;
        int right = n-1;

        while(left < right){
          int currentSum = nums[i] + nums[left] + nums[right];

          if(currentSum == target){
            return currentSum;// because here my diff will be minimum from the target which is going to be zero 
          }
          int diff = abs(target - currentSum);
          if(diff < maxDiff){
            maxDiff = diff;
            resultSum = currentSum;
          }
          if(currentSum < target){
            left++;
          }
          else{
            right--;
          }

          
        }
      }

      return resultSum;
    }
};