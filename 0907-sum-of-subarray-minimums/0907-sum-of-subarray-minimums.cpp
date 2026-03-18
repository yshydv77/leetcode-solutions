class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&arr){
      vector<int>ans(arr.size());
      stack<int>st;
      st.push(-1);
      for(int i = arr.size()-1 ; i>=0 ; i--){
        while(st.top() != -1 && arr[st.top()] > arr[i]){
          st.pop();
        }
        ans[i] = st.top();
        st.push(i);
      }

      // to simplify the calculation we replace the -1 in the answer array with the size of the arr
      for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i] == -1){
          ans[i] = arr.size();
        }
      }

      return ans;
    }
    vector<int>prevSmallerElement(vector<int>&arr){
      vector<int>ans(arr.size());
      stack<int>st;
      st.push(-1);
      for(int i = 0 ; i < arr.size() ; i++){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
          st.pop();
        }
        ans[i] = st.top();
        st.push(i);
      }

      // 0 se phele -1 aata hai toh we need not to worry about the calculation here
      return ans;
    }
   
    int sumSubarrayMins(vector<int>& arr) {
        long long  sum = 0 ;
        vector<int>nse = nextSmallerElement(arr);
        vector<int>pse = prevSmallerElement(arr);
       const long long MOD = 1000000007;
        for(int i = 0 ; i < arr.size() ; i++){

          // ni is next smaller element index for index ith element 
          //pi is prev smaller element index for index ith element
          int ni = nse[i];
          int pi = pse[i];

          //left_element is how much element is on the left including the ith element
          //right_element is how much element is on the right including the ith element
          int left_element = i - pi;
          int right_element = ni - i;

          // totoal_times_element_included means how many times the element is included in the sum  
          // ttei -> total times element included

          long long  ttei = (left_element * right_element) % MOD;
          sum += ((ttei % MOD) * (arr[i] % MOD)) % MOD;

        }
        sum = sum % MOD;
        return sum;
    }
};