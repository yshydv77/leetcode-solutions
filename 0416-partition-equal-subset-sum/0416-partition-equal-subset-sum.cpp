class Solution {
public:
    bool fun(vector<int>&nums , int csum , int tsum , int i , int n , bool ans , vector<vector<int>>&dp ){
        if(csum == tsum)
            return dp[i][csum] = true;

        if(i==n || csum > tsum)
            return false;

        if(dp[i][csum] != -1){
            return dp[i][csum];
        }


        bool c1 = fun(nums,csum + nums[i] , tsum , i+1,n , ans,dp);
        bool c2 = fun(nums, csum , tsum , i+1,n,ans,dp) ;
        ans = c1 || c2;
        return dp[i][csum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        if(totalSum % 2 != 0 ){
            return false;
        }   
        vector<vector<int>> dp(nums.size()+1, vector<int>(totalSum/2 + 1, -1));
        bool ans = fun(nums,0,totalSum/2 , 0 , nums.size() , ans , dp);
        return ans;
    }
};