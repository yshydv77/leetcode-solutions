class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&nums , int i ,int n , vector<int>diary){
        ans.push_back(diary);

        for(int j = i ; j < n ; j++){
            if(j>i && nums[j] == nums[j-1]){
                continue;
            }

            diary.push_back(nums[j]);
            fun(nums,j+1,n,diary);
            diary.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        fun(nums,0,nums.size(),{});
        return ans;
    }
};