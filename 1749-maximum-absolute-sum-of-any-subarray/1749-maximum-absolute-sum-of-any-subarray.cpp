class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prevminsum = nums[0];
        int prevmaxsum = nums[0];
        int ans = abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            int newminsum = min(nums[i],prevminsum+nums[i]) ;
            int newmaxsum = max(nums[i] , prevmaxsum+nums[i]);
            ans = max({ans,abs(newminsum) , newmaxsum});
            prevminsum = newminsum;
            prevmaxsum=newmaxsum;
        }
        return abs(ans);
    }
};