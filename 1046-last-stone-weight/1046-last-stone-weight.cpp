class Solution {
public:
int lastStoneWeight(vector<int>& stones) {
  int n = stones.size();
  if(n==1){
    return stones[0];
  }
  // mujhe at any point of time par two heaviest stone chahiye 
  // rule ->
  // x == y -> both smashes
  // x != y -> x smashes and y = y -x because x<=y given
  priority_queue<int>maxHeap(stones.begin() , stones.end());
  while (maxHeap.size() >= 2)
  {
    int y = maxHeap.top();
    maxHeap.pop();
    int x = maxHeap.top();
    maxHeap.pop();
    if(x<=y){
      y= y-x;
      maxHeap.push(y);
    }
  }
  if(maxHeap.empty()){
    return 0;
  }
  return maxHeap.top();
  
}
};