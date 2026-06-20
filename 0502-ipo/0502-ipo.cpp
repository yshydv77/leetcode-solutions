class Solution {
public:
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
  // approach 
  // create nd store all the pairs of capital and profits
  // sort this vector of pair in increasing order
  // k values choose karni hai from this vector
  // vo values vo choose karni hai jo ki w se chote captial vali ho 
  // ab in values ke profit ko store karlo and humein har choice mein se vo profit chahiye jisme muje max profit ho raha ho

  vector<pair<int,int>>a;
  for(int i = 0 ; i < profits.size() ; i++){
    a.push_back({capital[i] , profits[i]});
  }

  priority_queue<int>maxHeap;
  sort(a.begin(),a.end());
  int idx = 0 ;
  while(k--){
    while(idx < a.size()){
      if(a[idx].first > w){
        break;
      }
      maxHeap.push(a[idx].second);
      idx++;
    }
    if(maxHeap.empty()){
      return w;
    }
    w += maxHeap.top();
    maxHeap.pop();
  }


  return w;
}
};