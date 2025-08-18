class Solution {
public:
    void solve(vector<int>&nums , vector<vector<int>>&ans , vector<int>output , int index){
        // base case
        if(index >= nums.size()){
            // puri array ko traveerse kar liya hia
            // mera output tyaar hai
            ans.push_back(output);
            return ;
        }
        // include
        int num = nums[index];
        output.push_back(num);
        solve(nums , ans , output , index+1);

        // exclude
        output.pop_back();
        solve(nums , ans , output , index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0 ;
        solve(nums, ans ,output , index);
        sort(ans.begin() , ans.end());
        return ans;
    }
};