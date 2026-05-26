class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      // time complexity :- O(n) because i is moving forward and j is also moving forward only for the time complexity to be O(n^2) inner loop should move from 0 to n while the outer loop is moving from 0 to n 
      // in this case outer loop is moving from o to n but the inner loop is moving from i to
       
        int i = 0 ;
        int j = 1;
        while(j < nums.size()){
          if(nums[j] == nums[j-1]){
            j++;
          }
          else{

          i++;
          nums[i] = nums[j];
          j++;
          }
            
        }

        return i+1;
    }
};