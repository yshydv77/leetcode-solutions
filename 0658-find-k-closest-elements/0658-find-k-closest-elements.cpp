class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k,int x) {
  int low = 0;
  int high= arr.size()-1;
  while (high-low+1 > k)
  {
    int xLow = abs(x-arr[low]);
    int xHigh = abs(x-arr[high]);

    if(xLow < xHigh){
      high--;
    }
    else if(xLow > xHigh){
      low++;
    }
    else{
      high--;
    }
  }
  vector<int>ans;
  for(int i = low ; i<= high ; i++){
    ans.push_back(arr[i]);
  }

  return ans;
  
}
// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//   int n = arr.size();
//   // closest bola hai k closest hai toh 
//   // closest pucha haii toh max heap ka use karnege
//   priority_queue<pair<int,int>>pq;
//   for (int i = 0; i < n; i++)
//   {
//     if(pq.size() < k ){
//       pq.push({abs(x-arr[i]) , arr[i]});
//     }
//     else{
//       pq.push({abs(x-arr[i]) , arr[i]});
//       pq.pop();
//     }
//   }
//   vector<int>ans;
//   while (!pq.empty())
//   {
//     ans.push_back(pq.top().second);
//     pq.pop();
//   }
//   // sort(ans.begin(),ans.end());
//   return ans;
  
  

// }
};