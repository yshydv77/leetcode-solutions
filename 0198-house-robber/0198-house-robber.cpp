class Solution {
public:

    int fun(vector<int>&nums , int i , int n, int free , vector<vector<int>>&dp){

        if(i == n){
            return 0;
        }
        if(dp[i][free] != -1){
            // value is already stored in the dp so i do not to calculate that again 
            return dp[i][free];
        }

        if(free == 0){
            // isko toh le hi nahi sakte hai 
            // this is the shortcut way to write and store the value of the fun 
            return dp[i][free] =  fun(nums,i+1 , n , 1 , dp);
        }
        else{
            // 2 choices are there 
            // 1 ki usko le lo and agar le lete hai toh free change hokar zero ho jayega
            // 2 ki usko mat lo agar nahi lete hai toh free =1 hi rahge 
            // and then return the max of both the calculated value

            int a1 = nums[i] + fun(nums , i+1 , n , 0 , dp);
            int a2 = fun(nums, i+1 , n , 1 , dp);
            return dp[i][free] = max(a1 , a2);
        }

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int free = 1;
        vector<vector<int>>dp(n , vector<int>(2,-1));
        return fun(nums,i,n,free,dp);

    }
};