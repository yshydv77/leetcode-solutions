class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int total_rows = matrix.size();
  int total_cols = matrix[0].size();
  int row = total_rows -1 ;
  int col = 0;
  while (row >= 0 && col < total_cols)
  {
    int ele = matrix[row][col];
    if(ele == target){
      return true;
    }
    if(ele > target){
      row--;
    }
    else{
      col++;
    }
  }
  return false;
  
}
};