class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double max_avg = -DBL_MAX;
      double avg ;

      int low =  0;
      int high =k-1;

      double sum = 0 ;
      for(int i = low ; i <= high ; i++){
        sum += nums[i];
      }
      

      avg = sum / k ;

      while(high < nums.size()){
        max_avg = (avg > max_avg) ? avg : max_avg;
        low++;
        high++;
        if(high >= nums.size()){
          break;
        }
        sum += (nums[high] - nums[low-1]);
        avg = sum/k;
      }

      return max_avg;
    }
};