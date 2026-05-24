class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_len = INT_MAX;
      int sum  = 0 ;

      // varialble size window hai isliye hum iske low and high ko zero se start karneg

      // hiring -> hiring mein first hire karlo and then next student par socho ki hire karna hai yaa  phir nahi iske liye hi hum sum mein value add karlo and then high ko plus plus kardo 
      // firing -> firing mein sum mein se value ghata do and low ko plus plus kardo 
      int low = 0 ;
      int high = 0;

      while(high < nums.size()){
        sum += nums[high];
        while(sum >= target){
          int len  = (high - low  + 1);
          min_len = min (min_len , len);

          sum -= nums[low];
          low++;
        }
        high++;
      }
      

    return (min_len == INT_MAX) ? 0 : min_len;
    }
};