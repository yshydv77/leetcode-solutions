class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  int n = arr.size();
  // closest bola hai k closest hai toh 
  // closest pucha haii toh max heap ka use karnege
  priority_queue<pair<int,int>>pq;
  for (int i = 0; i < n; i++)
  {
    if(pq.size() < k ){
      pq.push({abs(x-arr[i]) , arr[i]});
    }
    else{
      pq.push({abs(x-arr[i]) , arr[i]});
      pq.pop();
    }
  }
  vector<int>ans;
  while (!pq.empty())
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  sort(ans.begin(),ans.end());
  return ans;
  
  

}
};