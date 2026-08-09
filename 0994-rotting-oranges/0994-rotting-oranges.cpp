class Solution {
public:
bool isValid(int x_cord , int y_cord , int totalRows , int totalCols){
  if(x_cord < 0 || x_cord >= totalRows || y_cord < 0 || y_cord >= totalCols){
    return false;
  }
  return true;
}
int orangesRotting(vector<vector<int>> &grid)
{
  // bfs isliye lagega because yaha par ek rotten orange parallely uske aas paas ke fresh organes ko rotten mein convert karega
  queue<pair<int,int>>q;//store coordinate of rotten oranges
  int fresh = 0 ;
  int time = 0 ;
  int totalRows = grid.size();
  int totalCols = grid[0].size();

  for(int i = 0 ; i < totalRows ; i++){
    for(int j = 0 ; j < totalCols ; j++){
      if(grid[i][j] == 2){
        //rotten orange hai push it into the queue
        q.push({i,j});
        grid[i][j] = 5;
        // 5 is taken so that we do not go again to the 2 (rotten orange ) for distinguish purposes we have taken 5 
      }
      else if(grid[i][j] == 1){
        fresh++;
      }
    }
  }

  while(!q.empty() && fresh > 0){
    time++;
    int s = q.size();
    while(s--){
      pair<int,int>p = q.front();
      q.pop();
      int x[4] = {-1,1,0,0};
      int y[4] = {0,0,-1,1};
      for(int k = 0 ; k < 4 ; k++){
        int x_cord = x[k] + p.first;
        int y_cord = y[k] + p.second ;
        if(isValid(x_cord , y_cord , totalRows , totalCols) && grid[x_cord][y_cord] == 1){
          // fresh orange hona chahiye and valid cord hona chahiye  
          q.push({x_cord,y_cord});
          grid[x_cord][y_cord] = 5;
          fresh--;
        }
      }
    }
  }

  if(fresh > 0){
    return -1; //because ek aesa fresh orange bach gaya hai jaha tak pahuchna possible nahi hai toh return -1
  }
  return time;
}
};