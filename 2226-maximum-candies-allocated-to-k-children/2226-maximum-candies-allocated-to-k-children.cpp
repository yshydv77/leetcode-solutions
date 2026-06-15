class Solution {
public:
bool fun(vector<int>&candies , long long& k , int& guess){
  long long children = 0 ;
  int n = candies.size();
  for (int i = 0; i < n; i++)
  {
    children += (candies[i] / guess);
  }

  if(children >= k){
    return true;
  }
  return false;
  
}
int maximumCandies(vector<int>& candies, long long k) {
  int n = candies.size();
  int low = 1 ;
  int high = *max_element(candies.begin() , candies.end());
  int ans = 0;
  while (low <= high)
  {
    int guess = low + (high - low )/2;
    if(fun(candies , k , guess)){
      ans = guess;
      low = guess+1;
    }
    else{
      high = guess-1;
    }
  }
  return ans;
}
};