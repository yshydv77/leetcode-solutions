class Solution {
public:
    void solve(vector<int>&nums , int i , set<vector<int>>&st){
        if(i>= nums.size()){
            st.insert(nums);
            return ;
        }

        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i] , nums[j]);
            solve(nums , i+1 , st);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        int i = 0 ;
        solve(nums , i , st);
        vector<vector<int>>ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;

    }
};