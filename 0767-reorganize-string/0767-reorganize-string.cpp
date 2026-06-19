class Solution {
public:
string reorganizeString(string s) {
  // ye heap ka question isliye hai because
  // har point par mujhe letter jiski max freq hai vo chahiye and yekaam heap hi
  // kar sakta hia sabse phele toh ye pata kar lo ki har leeter ki freq kya hai
  unordered_map<char, int> freq;
  for (int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
  }

  priority_queue<pair<int, char>> pq;  // max heap banani hai
  for (auto&& it : freq) {
    pq.push({it.second, it.first});
  }
  string res = "";

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    if (res.empty() || res.back() != p.second) {
      res.push_back(p.second);
      p.first--;
      if (p.first > 0) {
        pq.push(p);
      }
    } else {
      if (pq.empty()) {
        return "";
      }
      auto p1 = pq.top();
      pq.pop();
      res.push_back(p1.second);
      p1.first--;
      if (p1.first > 0) {
        pq.push(p1);
      }
      pq.push(p);
    }
  }
  return res;
}
};