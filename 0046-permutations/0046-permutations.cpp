class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&nums , int i , int n, vector<int>diary){
        if(i == n){
            ans.push_back(nums);
            return;
        }

        for(int j = i ; j < n ; j++){
            swap(nums[j] , nums[i]);
            fun(nums,i+1,n,diary);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        fun(nums,0,n,{});
        return ans;
    }
};