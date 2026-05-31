class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMaxEnding = nums[0];
        int prevMinEnding = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int newMaxEnding = max({nums[i] , prevMaxEnding * nums[i] , prevMinEnding * nums[i]});
            int newMinEnding = min({nums[i] , prevMaxEnding * nums[i] , prevMinEnding * nums[i]});

            ans = max({ans , newMaxEnding , newMinEnding});
            prevMinEnding = newMinEnding;
            prevMaxEnding = newMaxEnding;
        }

        return ans;
    }
};