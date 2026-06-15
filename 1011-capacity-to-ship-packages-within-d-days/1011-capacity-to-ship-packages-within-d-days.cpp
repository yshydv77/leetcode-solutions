class Solution {
public:
bool fun(vector<int>& weights, int& days, int& guess) {
  int d = 0;
  int s = weights[0];
  for (int i = 1; i < weights.size(); i++) {
    if (s + weights[i] <= guess) {
      s += weights[i];
    } else {
      // iska matlab ye ha ki s+ weight[i] bada ho gaya hai
      d++;
      s = weights[i];
    }
  }

  if (s <= guess) {
    d++;
  }

  if (d <= days) {
    return true;
  }
  return false;
}
int shipWithinDays(vector<int>& weights, int days) {
  int low = *max_element(weights.begin(), weights.end());
  int high = accumulate(weights.begin(), weights.end(), 0);
  int ans = -1;
  while (low <= high) {
    int guess = low + (high - low) / 2;
    if (fun(weights, days, guess)) {
      ans = guess;
      high = guess - 1;
    } else {
      low = guess + 1;
    }
  }
  return ans;
}

};