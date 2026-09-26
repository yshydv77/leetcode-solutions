class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        bool allNegative=true;
        for(int i = 0 ; i <n ; i++){
            if(nums[i] >=0){
                allNegative=false;
                break;
            }
        }
        if(allNegative){
            int maxi = INT_MIN;
        for(auto it : nums){
            maxi = max(maxi , it);
        }

        return maxi;
        }
        int sum = accumulate(nums.begin() , nums.end(),0);
        int prevMaxSum = nums[0];
        int prevMinSum = nums[0];

        int ansMax = nums[0];
        int ansMin = nums[0];
        for(int i =1 ;i<n;i++){
            int newMaxSum = max(nums[i] ,prevMaxSum+nums[i]);
            int newMinSum = min(nums[i] , prevMinSum+nums[i]);
            ansMax = max(ansMax,newMaxSum);
            ansMin = min(ansMin,newMinSum);
            prevMaxSum = newMaxSum;
            prevMinSum = newMinSum;
        }

        return max(ansMax , sum - ansMin);

    }
};