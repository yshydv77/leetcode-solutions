class Solution {
public:
void getLeftMax(vector<int>&height, vector<int>&leftMax){
  int n = height.size();
  leftMax.push_back(height[0]);
  for(int i = 1 ; i < n ; i++){
    leftMax.push_back(max(leftMax.back() , height[i]));
  }

}
void getRightMax(vector<int>&height, vector<int>&rightMax){
  int n = height.size();
  rightMax.push_back(height[n-1]);
  for(int i = n-1;i>=0;i--){
    rightMax.push_back(max(rightMax.back() , height[i]));
  }
  reverse(rightMax.begin() , rightMax.end());
}
int trap(vector<int>& height) {
  // widht of each bar is 1
  int res = 0 ;
  vector<int>leftMax;
  vector<int>rightMax;
  getLeftMax(height,leftMax);
  getRightMax(height , rightMax);
  int n = height.size();
  for(int i = 0 ; i < n ;i++){
    res += (min(leftMax[i],rightMax[i]) - height[i]);
  }

  return res;
}
};