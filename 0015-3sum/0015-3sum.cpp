class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>ans;
        sort(a.begin() , a.end());
        int n = a.size();
        for(int i = 0 ; i < n-2 ; i++){
          int left = i+1;
          int right = n-1;

          int target = (a[i] * (-1));
          if(i>0 && a[i] == a[i-1]){
            continue;
          }
          // two sum approach for each i 
          while(left < right){
            int sum = a[left] + a[right];
            if(sum  < target){
              left++;
            }
            else if(sum > target){
              right--;
            }
            else{
              // sum == target
              vector<int>an;
              an.push_back(a[i]);
              an.push_back(a[left] );
              an.push_back(a[right]);
              ans.push_back(an);
              left++;
              right--;
              while(left < n && a[left] == a[left-1]){
                left++;
              }
              while(right>=0 && a[right]==a[right+1]){
                right--;
              }
            }
          }
        }
        return ans;
    }
};