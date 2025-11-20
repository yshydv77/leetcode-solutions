class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        vector<int>leftSum(n);
        vector<int>rightSum(n);
        int left = 0;
        int right = 0;
        for(int i =0 ;i< n ; i++){
          left = left + nums[i];
          right = right + nums[n-i-1];
          leftSum[i] = left;
          rightSum[n-1-i] = right;
        }

        for(int i = 0 ; i < n ; i++){
          if(leftSum[i] == rightSum[i]){
              ans = i;
              break;
          }
        }

        return ans;
    }
};