class Solution {
public:
int subarrayAtmostKDistinct(vector<int> &nums, int k)
{
    int low = 0;
    int high = 0;
    int cnt = 0;
    unordered_map<int, int> freq;
    for (high = 0; high < nums.size(); high++)
    {
        freq[nums[high]]++;
        while (freq.size() > k)
        {
            freq[nums[low]]--;
            if (freq[nums[low]] == 0)
            {
                freq.erase(nums[low]);
            }
            low++;
        }
        cnt += (high-low+1);
    }

    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    // array subarray excatlly k distinct integer hone chahiye n the subarray
    // sliding window lag sakta hai
    // variable sliding wnow

    int cnt = subarrayAtmostKDistinct(nums, k) - subarrayAtmostKDistinct(nums,k-1);
    return cnt;
}
};