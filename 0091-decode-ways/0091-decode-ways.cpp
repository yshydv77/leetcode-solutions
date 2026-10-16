class Solution {
public:

    int fun(int i , int n , string& s , vector<int>&dp){
        if(dp[i] != -1){
            return dp[i];
        }
        if(i==n){
            return dp[i] = 1; // one valid spliting done
        }

        if(s[i] == '0'){
            return dp[i] = 0; // there is no way to split 
        }

        int result = fun(i+1,n,s,dp);

        if(i+1<n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <='6')){
                result += fun(i+2,n,s,dp);
            }
        }
        return dp[i] = result;

    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        return fun(0,s.size() , s, dp);
    }
};