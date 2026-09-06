class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0;
        int freq0 = 0;
        int ans = 0;

        for (int high = 0; high < n; high++) {

            // Add new element to the window
            if (nums[high] == 0) {
                freq0++;
            }

            // Shrink window if zeros exceed k
            while (freq0 > k) {
                if (nums[low] == 0) {
                    freq0--;
                }
                low++;
            }

            // Current window is valid
            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};