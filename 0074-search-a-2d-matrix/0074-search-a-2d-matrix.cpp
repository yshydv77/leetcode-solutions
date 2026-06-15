class Solution {
public:
bool searchMatrix(vector<vector<int>>&matrix , int target){
  int total_rows = matrix.size();
  int total_cols = matrix[0].size();
  int low = 0 ;
  int high = (total_rows * total_cols)-1;
  while (low<=high)
  {
    int guess = low +(high-low)/2;
    int r = (guess / total_cols) ;
    int c = (guess % total_cols);
    int ele = matrix[r][c];
    if(ele == target){
      return true;
    }
    else if(ele < target){
      low = guess+1;
    }
    else{
      high = guess-1;
    }
  }
  return false;
  
}

};