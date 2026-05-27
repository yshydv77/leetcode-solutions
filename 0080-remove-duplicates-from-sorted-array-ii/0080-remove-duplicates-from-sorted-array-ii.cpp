class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      
      int low = 0 ;
      int high = 0;

      while(high < nums.size()){
        int count = 1;
        while(high+1 < nums.size() && nums[high] == nums[high+1]){
          high++;
          count++;
        }

        int mini = min(2,count);

        for(int i = 0 ; i< mini ; i++){
          nums[low] = nums[high];
          low++;
        }

        high++;
      }


      return low;

    }
};