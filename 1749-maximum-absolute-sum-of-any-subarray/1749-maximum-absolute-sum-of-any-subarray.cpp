class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxAns = nums[0];
        int minAns = nums[0];

        int prevMinEnding = nums[0];
        int prevMaxEnding = nums[0];
        for(int i =1 ; i < nums.size();i++){
            int newMinEnding = min({nums[i] , nums[i]+prevMinEnding});
            int newMaxEnding = max({nums[i] , nums[i] + prevMaxEnding});
            maxAns = max({maxAns , newMaxEnding});
            minAns = min({minAns , newMinEnding});
            prevMinEnding = newMinEnding;
            prevMaxEnding = newMaxEnding;
        }

        minAns = abs(minAns);
        return (maxAns >= minAns) ? maxAns : minAns;
    }
};