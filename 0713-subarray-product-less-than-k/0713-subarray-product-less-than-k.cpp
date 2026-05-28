class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    // array subarray count no of subarray whose product is less than k 
    // variable window size problem
    if(k<=1){
        return 0;
    }
    int low = 0;
    int high  = 0;
    int cprod = 1;
    int count = 0 ;
    for(high = 0 ; high < nums.size() ; high++){
        cprod *= nums[high];
        while(cprod >= k){
            cprod/=nums[low];
            low++;
        }
        // cprod == k // cprod < k
      
        if(cprod < k ){
            count+=(high-low+1);
        }
    }

    return count;
}
};