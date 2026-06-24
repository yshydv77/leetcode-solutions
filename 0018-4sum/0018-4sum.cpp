class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        // 4sum 
        // array -> sorted (unique) -> 4sum

        sort(a.begin() , a.end());
        int n = a.size();
        vector<vector<int>>ans;
        for(long long  i = 0 ; i < n-3 ; i++){
            if(i > 0 && a[i] == a[i-1]){
                continue;
            }

            for(long long j = i+1 ; j < n-2 ; j++){
                if(j > i+1 && a[j] == a[j-1]){
                    continue;
                }


              
                long long  low = j+1;
                long long high = n-1;

                while(low < high){
                    long long  s = (long long) a[i] + a[j] + a[low]+ a[high];
                    if(s < target){
                        low++;
                    }
                    else if(s > target){
                        high--;
                    }
                    else{
                        ans.push_back({a[i] , a[j] , a[low] , a[high]});
                        low++;
                        high--;
                        while(low < high && a[low] == a[low-1]){
                            low++;
                        }
                        while(low<high && a[high] == a[high+1]){
                            high--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};