class Solution {
public:

// combination sum
void fun(vector<int>&candidates , int target , int i , int n , vector<int>ds , vector<vector<int>>&ans){
    if(i==n){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    // pick that particular element
    if(candidates[i] <= target){
        ds.push_back(candidates[i]);
        // since hum multiple times ek hi element ko le sakte hai toh isliye i change nahi hoga
        fun(candidates,target-candidates[i] , i , n , ds, ans);
        // backtrack
        ds.pop_back();
    }

    // hum iss particular element ko pick nahi karenge
    fun(candidates , target , i+1,n,ds,ans);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    int n = candidates.size();
    int i = 0 ;
    fun(candidates,target,i,n,ds , ans);
    return ans;
}

};