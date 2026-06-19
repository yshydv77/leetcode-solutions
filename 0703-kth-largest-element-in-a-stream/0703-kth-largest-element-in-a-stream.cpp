class KthLargest {
 public:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
  KthLargest(int k, vector<int>& nums) {
    this->k=k;
    for (int i = 0; i < nums.size(); i++) {
      int ele = nums[i];
      if (pq.size() < k) {
        pq.push(ele);
      } else {
        if (ele < pq.top()) {
          continue;
        } else {
          pq.pop();
          pq.push(ele);
        }
      }
    }
  }

  int add(int val) {

    if(pq.size() < k ){
      pq.push(val);
      return pq.top();
    }

    if (val < pq.top()) {
      return pq.top();
    } else {
      pq.pop();
      pq.push(val);
      return pq.top();
    }
  }
};
