class Solution {
public:
double fun(pair<int, int>& a) {
  return sqrt((double)(a.first * a.first) + (a.second * a.second));
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  // distance nikal
  // jiska distance minimum vo closest hoga
  // max heap use hogi
  // because complex ho jayega pair<int,pair<int,int>> we are storing here
  // distance and the points
  // max heap bana li hia

  priority_queue<pair<double, int>> pq;
  for (int i = 0; i < points.size(); i++) {
    pair<int, int> point = {points[i][0], points[i][1]};
    double dis = fun(point);
    pair<double, int> p = {dis, i};
    if (pq.size() < k) {
      pq.push(p);
    } else {
      pq.push(p);
      pq.pop();
    }
  }
  vector<vector<int>> ans;
  while (!pq.empty()) {
    auto pp = pq.top();
    ans.push_back(points[pp.second]);
    pq.pop();
  }

  return ans;
}
};