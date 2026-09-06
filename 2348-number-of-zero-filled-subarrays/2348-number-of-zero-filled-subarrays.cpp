class Solution {
public:
long long sumNaturalNumber(long long num) {
  long long sum = 0;
  for (long long i = 1; i <= num; i++) {
    sum += i;
  }
  return sum;
}
long long zeroFilledSubarray(vector<int>& nums) {
  long long ans = 0;
  for (long long i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      int count = 1;i++;
      while (i< nums.size() && nums[i] == 0) {
        count++;
        i++;
      }
      ans += (count == 1 ) ? 1 : sumNaturalNumber(count);
    }
  }

  return ans;


}
};