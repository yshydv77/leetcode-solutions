class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
      int i = 0 ;
      int j = 0;

      vector<int>ans;
      while(i< m && j < n){
        if(a[i] < b[j]){
          ans.push_back(a[i]);
          i++;
        }
        else if(b[j] < a[i]){
          ans.push_back(b[j]);
          j++;
        }
        else{
          ans.push_back(a[i]);
          i++;
          ans.push_back(b[j]);
          j++;
        }
      }

      while(i<m){
        ans.push_back(a[i]);
        i++;
      }
      while(j<n){
        ans.push_back(b[j]);
        j++;
      }

      for(int i = 0 ; i < m+n ; i++){
        a[i] = ans[i];
      }
    }
};