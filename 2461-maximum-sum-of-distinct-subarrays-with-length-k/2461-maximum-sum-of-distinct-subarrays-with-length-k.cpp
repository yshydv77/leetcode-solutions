class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // fixed window size
        long long maxSum = 0;
        int low = 0;
        int high = k - 1;
        long long sum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i <= high; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }

        if (freq.size() == k) {
            maxSum = max(maxSum, sum);
        }

        for (high = k; high < nums.size(); high++) {
            freq[nums[low]]--;
            sum -= nums[low];
            if (freq[nums[low]] == 0) {
                freq.erase(nums[low]);
            }
            low++;
            freq[nums[high]]++;
            sum += nums[high];

            if (freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return (maxSum == INT_MIN) ? 0 : maxSum;
    }
};