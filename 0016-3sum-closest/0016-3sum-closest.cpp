class Solution {
public:
    void twoSumHelper(int f , int &target ,int &closestSum, vector<int>&nums){
        int i = f+1;
        int j = nums.size()-1;

        while(i < j){
            int sum = nums[f] + nums[i] + nums[j];

            int diff = abs (sum - target);

            int bdiff = abs(closestSum - target);

            if(diff < bdiff){
                bdiff = diff;
                closestSum = sum;
            }

            if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }else{
                i++;
                j--;
                while(i<j && nums[i] == nums[i-1]){
                    i++;
                }
                while(i<j && nums[j] == nums[j+1]){
                    j--;
                }
            }

        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int f = 0 ; f < nums.size() ; f++){
            // two sum apply karva do 
            twoSumHelper(f , target ,closestSum, nums);
        }

        return closestSum;
    }
};