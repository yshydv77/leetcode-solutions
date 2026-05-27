class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
{
    // array subarray min length subarray whose sum>= target
    int low = 0;
    int csum = 0;
    int min_len = INT_MAX;
    for(int high = 0 ; high < nums.size() ; high++){
        csum += nums[high];
        while(csum >= target){
            int len = high-low+1;
            min_len = min(min_len , len);

            csum -=nums[low ];
            low++;
        }
    }

    return (min_len == INT_MAX ? 0 : min_len) ;
}
};