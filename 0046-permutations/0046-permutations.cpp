class Solution {
public:
    vector<vector<int>>ans;
    unordered_set<int>st;

    void fun(vector<int>&nums  , int n , vector<int>diary){
        if(diary.size()==n){
            ans.push_back(diary);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(st.find(nums[i]) == st.end()){
            diary.push_back(nums[i]);
            st.insert(nums[i]);
            fun(nums,n,diary);
            diary.pop_back();
            st.erase(nums[i]);
            }

        }



    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>diary;
       
            fun(nums,n,diary);
        
        
        return ans;
    }
};