class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int low = 0;
        int high = 0 ;
        while(high < nums.size()){
            if(nums[high] == val){
                high++;
            }
            else if(nums[low] == val && nums[high] != val){
                swap(nums[low] , nums[high]);
                low++;
                high++;
            } 
            else if(nums[low] !=val && nums[high] != val){
                low++;high++;
            }
        }

        return low;  
    }
};