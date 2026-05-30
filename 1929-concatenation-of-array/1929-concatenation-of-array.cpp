class Solution {
public:
    void fun (vector<int>&nums , vector<int>&ans){
        for(int i = 0 ;i < nums.size() ; i++){
            ans.push_back(nums[i]);
        }
    }
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        fun(nums,ans);
        fun(nums,ans);
        return ans;
    }
};