class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      if(nums.size() == 1){
        nums[0] *= nums[0];
        return nums;
      }
      vector<int>ans;
      int i = 0;
      int j = nums.size()-1;
      while(i<=j){
        int sqi = nums[i] * nums[i];
        int sqj = nums[j] * nums[j];

        if(sqi < sqj){
          ans.push_back(sqj);
          j--;
        }
        else if(sqi > sqj){
          ans.push_back(sqi);
          i++;
        }
        else if(sqi == sqj && i != j ){
          ans.push_back(sqi);
          ans.push_back(sqj);
          i++;
          j--;
        }
        else{
          ans.push_back(sqi);
          i++;
          j--;
        }
      }
      reverse(ans.begin() , ans.end());
      
      return ans;
    }
};