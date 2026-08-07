class Solution {
public:
bool isValid(int row, int col, int totalRows, int totalCols)
{
  if (row < 0 || row >= totalRows || col < 0 || col >= totalCols)
  {
    return false;
  }
  return true;
}
void dfs(vector<vector<char>> &grid, int totalRows, int totalCols, int i, int j, vector<vector<bool>> &visited)
{
  visited[i][j] = true;

  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};
  for (int k = 0; k < 4; k++)
  {
    int row = i + x[k];
    int col = j + y[k];
    if (isValid(row, col, totalRows, totalCols) && grid[row][col] == '1' && visited[row][col] == false)
    {
      dfs(grid, totalRows, totalCols, row, col, visited);
    }

  }

  return ;
}
int numIslands(vector<vector<char>> &grid)
{
  int totalRows = grid.size();
  int totalCols = grid[0].size();
  vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
  int numOfIsland = 0;
  for (int i = 0; i < totalRows; i++)
  {
    for (int j = 0; j < totalCols; j++)
    {
      if (grid[i][j] == '1' && visited[i][j] == false)
      {
        dfs(grid, totalRows, totalCols, i, j, visited);
        numOfIsland++;
      }
    }
  }
  return numOfIsland;
}

};