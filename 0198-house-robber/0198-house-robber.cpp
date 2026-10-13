class Solution {
public:
    int fun(vector<int>&nums , int n , int i , vector<vector<int>>&dp , int free){
        if(i==n){
            return 0;
        }

        if(dp[i][free] != -1){
            return dp[i][free];
        }

        if(free == 0){
            return dp[i][free] = fun(nums,n,i+1,dp,1);
        }

        int c1 = nums[i] + fun(nums,n,i+1,dp,0);
        int c2 = fun(nums,n,i+1,dp,1);
        return dp[i][free] = max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1);
        for(int i = 0 ; i <n ; i++){
            vector<int>t(2,-1);
            dp[i]=t;
        }
        int ans = fun(nums,n,0,dp,1);
        return ans;
    }
};