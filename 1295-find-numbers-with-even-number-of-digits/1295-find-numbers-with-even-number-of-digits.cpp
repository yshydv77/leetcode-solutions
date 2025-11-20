class Solution {
public:
    int noOfDigitCalculator(int num){
      int count = 0;
      while(num != 0 ){
        count++;
        num = num/10;
      }
      return count;
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto it : nums){
          if(noOfDigitCalculator(it) % 2 == 0)
            cnt++;
        }

        return cnt;
    }
};