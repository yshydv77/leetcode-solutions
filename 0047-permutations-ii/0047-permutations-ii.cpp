class Solution {
public:
    vector<vector<int>> ans;
    int n ;

    void fun(unordered_map<int,int>&mp , vector<int>temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return ;
        }

        for(auto &[num , count] : mp){
            if(count == 0){
                continue;
            }

            temp.push_back(num);
            mp[num]--;
            fun(mp,temp);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &num : nums){
            mp[num]++;
        }

 n = nums.size();
        fun(mp , {});
        return ans;
    }
};