class Solution {
public:

bool isSufficient(vector<int>& p, long long k, long long h) {
  long long hours = 0;
  for (int i = 0; i < p.size(); i++) {
    long long h1 = p[i] / k;
    long long h2 = (p[i] % k != 0) ? 1 : 0;
    hours += (h1 + h2);
  }
  return hours <= h;
}
int minEatingSpeed(vector<int>& p, long long h) {
  long long maxi  = *max_element(p.begin() , p.end());
  long long low = 1;
  long long high = maxi;
  long long ans = -1;

  // kitna time lagega khane mein
  // int hours  =
  // int h =

  while (low <= high) {
    long long k = low + (high - low) / 2;
    // if k is sufficient speed hai toh
    if (isSufficient(p, k, h)) {
      ans = k;
      high = k - 1;
    }
    // nahi hai toh right jana padega
    else {
      low = k + 1;
    }
  }

  return ans;
}

};