class Solution {
public:
int majorityElement(vector<int>& nums) {
  int candidate = 0;
  int counter = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (counter == 0) {
      // iska matlab mera new candidate aagaya hai
      // yaa phir mera phele hi elemenet hia
      candidate = nums[i];
      counter = 1;
    }

    else if ( candidate == nums[i]) {
      counter++;
    }
    else if(candidate != nums[i]){
      counter--;
    }
  }

  return candidate;
}
};