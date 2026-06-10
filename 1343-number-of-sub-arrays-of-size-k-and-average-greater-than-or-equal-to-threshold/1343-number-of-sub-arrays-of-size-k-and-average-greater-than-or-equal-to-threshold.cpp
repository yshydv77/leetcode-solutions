class Solution {
public:
int numOfSubarrays(vector<int>& arr, int k, int threshold) {
  // array subarray average greater than threshold
  // fixed slindng window
  int low = 0;
  int high = k - 1;
  int count = 0;
  int sum = 0;
  // first window
  for (int i = low; i <= high; i++) {
    sum += arr[i];
  }

  if (sum / k >= threshold) {
    count ++;
  }

  while (high < arr.size()) {
    sum -= arr[low];
    low++;
    high++;
    if (high == arr.size()) {
      break;
    }
    sum += arr[high];
    if (sum / k >= threshold) {
      count ++;
    }
  }

  return count;
}
};