class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = INT_MIN;
        int n = nums.size();
        int cnt = 0 ;
        for(int i = 0 ; i  < n ; i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                max1 = max(cnt , max1);
                cnt = 0 ;
            }
        }
        max1 = max(cnt , max1);
        return max1;
    }
};