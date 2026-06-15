class Solution {
public:
bool fun(vector<int>&citations , int& guess ){
  int paper = 0;
  int cite = 0;
  int n = citations.size();
  for(int i = 0 ; i < n ; i++){
    if(citations[i] >= guess){
      paper++;
      cite++;
    }
  }
  if(paper >= guess){
    return true;
  }

  return false;
}

// h index
int hIndex(vector<int>& citations) {
  int n = citations.size();
  int low = 0 ;
  int high = *max_element(citations.begin() , citations.end());
  int ans = -1;
  while (low <= high  )
  {
    int guess = low + (high - low)/2;
    if(fun(citations,guess)){
      ans = guess;
      low = guess+1;
    }
    else{
      // if no 
      high = guess-1;
    }
  }
  
  return ans;

}
};