class Solution {
public:
//maximum product subarray
int maxProduct(vector<int> &nums)
{
    if(nums.size() == 1){
        return nums[0];
    }
    int maxending = nums[0];
    int ans = nums[0];
    int minending = nums[0];
    int oldmax = nums[0];
    int oldmin = nums[0];
    for(int i =1 ;i<nums.size();i++){

        int opt1 = nums[i];
        int opt2 = nums[i] * oldmax;
        int opt3 = nums[i] * oldmin;
        maxending = max(opt1 , max(opt2,opt3));
        minending = min(opt1, min(opt2, opt3));
        ans = max(ans , maxending);
        oldmax = maxending;
        oldmin = minending;
    }

    return ans;
}
};