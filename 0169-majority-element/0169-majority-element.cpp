class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ;i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int majf = INT_MIN;
        int maje = -1;
        for(auto it  : mp){
            if(majf < it.second){
                majf = it.second;
                maje = it.first;
            }
        }
        return maje;
    }
};