class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i = 0 ; i < nums1.size() ; i++){
            st1.insert(nums1[i]);
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            st2.insert(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(auto&&it : st1){
            mp[it]++;
        }
        for(auto&&it : st2){
            mp[it]++;
        }
        for(auto&&it : mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};