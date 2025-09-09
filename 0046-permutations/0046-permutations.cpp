class Solution {
public:
    void solve(vector<int>& nums , int i ,  vector<vector<int>>&ans){
        // base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        // har ek value of i ke liye j se start hokar values jo hai unhe hume swap karna 
        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i],nums[j]);// ek character ke liye kardiya baki ke liye recursion sambhal lega
            solve(nums, i+1 , ans);
            // back track karna hoga taki orignal nums same rahe
            swap(nums[i], nums[j]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums , 0 , ans);
        return ans;
    }
};