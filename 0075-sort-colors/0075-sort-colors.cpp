class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 ;
        int mid = 0;
        int high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                // zero ke liye low wala hai 
                // toh uske sath mein swap lkarva do 
                swap(nums[low] , nums[mid]);
                mid++;low++;
            }
            else if(nums[mid] == 1){
                mid++;
                // 1 ke liye mid hi hai vahi current element ko track kar raha hai toh 
            }
            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
        
    }
};