class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // array sort karne se faayada hoga and count karna hai two sum whose sum is lees than target
        // two pointer pattern ka qustion hai 
        sort(nums.begin(), nums.end());
        int count = 0 ;
        int low  = 0 ;
        int high = nums.size()-1;
        while(low<high){
            int sum = nums[low]+nums[high];
            if(sum<target){
                count+=(high-low);
                low++;
            }
            else if(sum >= target){
                high--;
            }
           
        }
        return count;
    }
};