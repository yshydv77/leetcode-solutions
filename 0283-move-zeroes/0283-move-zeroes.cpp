class Solution {
public:
    
void moveZeroes(vector<int> &nums)
{
    if(nums.size() == 1)return;
    int low = 0 ;
    int high =0;
    while(high < nums.size()){
        if(nums[high] == 0){
            high++;
        }
        else if(nums[low] == 0 && nums[high] != 0 ){
            swap(nums[low] , nums[high]);
            low++;
            high++;
        }
        else if(nums[low] != 0 && nums[high] != 0){
            low++; high++;
        }
        
    }
}
};