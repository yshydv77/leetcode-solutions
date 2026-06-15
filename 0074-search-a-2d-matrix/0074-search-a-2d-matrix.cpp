class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();
  int row = n;
  int col = matrix[0].size();
  int low = 0 ;
  int high = row-1;
  while (low <= high)
  {
    int guess = low + (high - low)/2;
    if(target >= matrix[guess][0] && target <= matrix[guess][col-1]){
      // isme element lie karta hia
      int l = 0;
      int h = col-1;
      while (l <= h)
      {
        int g = l + (h-l)/2;
        int ele = matrix[guess][g];
        if(ele == target){
          return true;
        }
        else if(ele < target){
          l = g+1;
        }
        else{
          h = g-1;
        }
      }
      return false;
      
    }
    else if(target < matrix[guess][0]){
      high = guess-1;
    }
    else{
      low = guess+1;
    }
  }

  return false;
  
}
};