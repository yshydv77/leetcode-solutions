class Solution {
public:
    int fun(vector<int>&nums , int n , vector<vector<int>>&dp , int i , int prev ){
        // yaha par jab prev = -1 hoga tab dp mein -1 access karne par segmentation fault aajayega 
        // usko handle karne ke liye values ko hum prev+1 mein store karenge but vo vaue prev vali value hogi 


        if(i == n){
            return 0; // because at the end we got nothing
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        if(prev == -1 || nums[i] >nums[prev]){
            // then we have two choices
            // first -> include that
            // second -> do not include that
            int c1 = 1 + fun(nums, n , dp , i+1 , i);
            int c2 = fun(nums,n,dp,i+1,prev);
            return dp[i][prev+1] = max(c1,c2);
        }

        else{
            // we do not have the choices 
            return dp[i][prev+1] = fun(nums,n,dp,i+1,prev);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int i = 0;
        vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        // because yaha par i and prev change hoga and both are ranged from 0 to n 
        return fun(nums , n , dp ,i , prev );
    }
};