class Solution {
public:
int timeRequiredToBuy(vector<int>& tickets, int k) {
  queue<pair<int, int>> q;
  int n = tickets.size();
  for (int i = 0; i < n; i++) {
    q.push({tickets[i], i});
  }

  int time = 0;

  while (true) {
    pair<int, int> pq = q.front();
    q.pop();
    if (pq.second == k && pq.first == 0) {
      break;
    }

    else {
      time++;
      pq.first = pq.first - 1;
      if (pq.first == 0 && pq.second != k) {
        continue;
      } else if (pq.first == 0 && pq.second == k) {
        return time;
      }
      q.push(pq);
    }
  }

  return time;
}
};