class Solution {
public:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  int n = nums2.size();
  vector<int> ans(n);
  stack<int> st;
  ans[n - 1] = -1;
  st.push(nums2[n - 1]);
  // finding next greater elements of nums2

  for (int i = n - 2; i >= 0; i--) {
    while (!st.empty() && st.top() <= nums2[i]) {
      st.pop();
    }
    if (st.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = st.top();
    }

    st.push(nums2[i]);
  }

  vector<int> a(nums1.size());
  for (int i = 0; i < nums1.size(); i++) {
    int ele = nums1[i];
    int ele_ind = -1;
    for (int j = 0; j < nums2.size(); j++) {
      if (ele == nums2[j]) {
        ele_ind = j;
        break;
      }
    }
    a[i] = ans[ele_ind];
  }
  return a;
}
};