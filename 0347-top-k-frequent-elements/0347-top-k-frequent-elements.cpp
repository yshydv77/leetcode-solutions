class Solution {
public:
struct cmp {
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    // on what basis mujhe elements sort karne hai
    // frequency ke basis par element ko sort karna hai
    if (a.second != b.second) {
      return a.second > b.second;
    }
    return a.first > b.first;
  }
};
// O(n) + N*O(logN) + O(logN) = O(NlogN)
vector<int> topKFrequent(vector<int>& nums, int k) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>
      pq;  // min heap priority queue
  unordered_map<int, int> freq;
  for (auto i = 0; i < nums.size(); i++) {
    freq[nums[i]]++;
  }
  vector<pair<int, int>> v(freq.begin(), freq.end());

  for(int i = 0 ; i < k ; i++){
    auto [freq , ele] = v[i];
    pq.push({freq,ele});
  }

  for (int i = k; i < v.size(); i++) {
    pair<int, int> ele = {v[i].first, v[i].second};
    if (ele.second < pq.top().second) {
      continue;
    } else {
      pq.pop();
      pq.push(ele);
    }
  }

  vector<int> ans;
  while (pq.empty() == false) {
    ans.emplace_back(pq.top().first);
    pq.pop();
  }

  return ans;
}

// vector<int> topKFrequent(vector<int>& nums, int k) {
//   // space complexity :- O()
//     unordered_map<int,int>freq;   // O(n)
//     for(auto &it : nums){
//         freq[it]++; //O(1)
//     }

//     vector<int>ans;
//     priority_queue<pair<int,int>>pq; // O(k)

//     for(auto &it : freq){ // O(k* logK)
//         pq.push({it.second , it.first});
//     }

//     while(pq.empty() == false && k--){
//         ans.push_back(pq.top().second);
//         pq.pop();
//     }
//     //time complexity :- O(n)
//     //O(n) -> space complexity 
//     return ans;


// }
};