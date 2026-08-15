class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n) {
        // dp ka question isliye hai because mujhe iss process mein particular value of n ko calculate karna pad raha hai 
        // isliye dp mein value ko store kar lenge and then use karnege 
        
        // base case 
        if(n == 1 || n == 2){
            return n;
        }

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        int a1 = climbStairs(n-1);
        int a2 = climbStairs(n-2);
        int ans = a1 + a2 ;
        // yaha par aaye hai iska matlab ye hai ki meine kabhi bhi ye ans nahi dekha tha toh dp mein store kar lenga
        dp[n] = ans;
        return ans;
    }
};