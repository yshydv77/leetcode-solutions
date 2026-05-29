class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // two pointer question 
        int i = 0 ;
        int j  = nums.size()-1;
        while(i<j){
            if(nums[i]%2 == 0){
                //ith element is even 
                i++;
            }
            else if(nums[i] % 2  != 0 && nums[j]%2 == 0 ){
                // odd number ha i
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }
            else if(nums[j]%2 != 0) {
                j--;
            }
        }

        return nums;
    }
};