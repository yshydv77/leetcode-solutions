class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i= 0 ; i< nums.size() ; i++){
          if(nums[i] == 1){
            cnt++;
          }
          else{
            cnt = 0;
          }
          maxi = max(maxi , cnt);
        }
        return maxi;

        // my method
        // for(int i = 0 ; i  < n ; i++){
        //     if(nums[i] == 1){
        //         cnt++;
        //     }
        //     else{
        //         max1 = max(cnt , max1);
        //         cnt = 0 ;
        //     }
        // }
        // max1 = max(cnt , max1);
        // return max1;
    }
};