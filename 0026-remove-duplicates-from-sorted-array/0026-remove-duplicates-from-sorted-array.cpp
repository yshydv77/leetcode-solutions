class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
          return 1;
        }
        if(nums.size() == 2){
          if(nums[0] == nums[1]){
            return 1;
          }
          else{
            return 2;
          }
        }

        int i = 0 ;
        int j = 0;
        while(i< nums.size() && j < nums.size()){
          // equl 
          while(j < nums.size() && nums[i] == nums[j]){
            j++;
          } 
          // not equal 
          if(j < nums.size()){
            i++;
            nums[i] = nums[j];
          }
            
        }

        return i+1;
    }
};