class Solution {
public:
    vector<int>nse(vector<int>&arr){
      stack<int>st;
      st.push(-1);
      vector<int>ans(arr.size());
      for(int i = arr.size()-1 ; i>=0; i--){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
          st.pop();
        }
        ans[i] = st.top();
        st.push(i);
      }

      for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i] == -1){
          ans[i] = arr.size();
        }
      }

      return ans;
    }

    vector<int>pse(vector<int>&arr){
      stack<int>st;
      st.push(-1);
      vector<int>ans(arr.size());
      for(int i =0;i < arr.size() ; i++){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
          st.pop();
        }
        ans[i] = st.top();
        st.push(i);

    }
      return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>n = nse(heights);
        vector<int>p = pse(heights);

        vector<int>area;
        for(int i = 0 ; i  < heights.size() ; i++){
          int ar = heights[i] * (n[i] - p[i] -1);
          area.push_back(ar);

        }

        int max_area = INT_MIN;
        for(auto it : area){
          if(max_area < it){
            max_area = it;
          }
        }
        return max_area;
    }
    
};