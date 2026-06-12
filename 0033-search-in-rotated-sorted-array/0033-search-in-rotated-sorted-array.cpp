class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    // 1 , 3 -> array
    // 1 -> target
    // -1 -> output
    // 0 -> expected
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        // find the minimum
        int low = 0;
        int high = nums.size() - 1;
        int mini = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // need to find out that part which is the minimum
            if (nums[mid] > nums[nums.size() - 1]) {
                // we are in the part 2
                low = mid + 1;
            } else {
                mini = mid;
                high = mid - 1;
            }
        }

        // so now we have the minimum ans

        // if we have the minimum answer then we have successfully find out the
        // search range mini ki do value hi possible hai yaa toh vo 0 aajaye ya
        // phir vo koi index ayega
        int ans1 = -1;
        int ans2 = -1;

        int low1 = 0;
        int high1 = mini - 1;
        ans1 = binarySearch(nums, low1, high1, target);

        int low2 = mini;
        int high2 = nums.size() - 1;
        ans2 = binarySearch(nums, low2, high2, target);
        if (ans1 == -1) {
            return ans2;
        }
        return ans1;
    }
};