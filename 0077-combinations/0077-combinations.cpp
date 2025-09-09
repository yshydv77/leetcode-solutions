class Solution {
public:
    void solve(int n, int k ,int i , vector<int>&output ,  vector<vector<int>>&ans){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        
    
     
        for(int j  = i ; j <= n ; j++){
            output.push_back(j);
            solve(n , k , j+1, output, ans);
            output.pop_back();
        }
       
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        int i = 1;
        vector<int>output;
        solve(n, k , i , output , ans);
        return ans;
    }
};