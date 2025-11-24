class Solution {
public:
    void twoSumHelper(int f , vector<int>&n , vector<vector<int>>&ans){
        int i = f+1;
        int j  = n.size()-1;

        while(i < j){
            int sum = n[f] + n [i]  + n[j];
            if(sum > 0 ){
                j = j -1;
            }else if(sum < 0 ){
                i = i + 1;
            }else{
                ans.push_back({n[f] , n[i] , n[j]});
                i++;
                j--;

                while(i < j && n[i] == n[i-1]){
                    i++;
                }
                while(i<j && n[j] == n[j+1]){
                    j--;
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& n) {
        vector<vector<int>>ans;
        sort(n.begin() , n.end());

        for(int f = 0 ; f < n.size() ; f++){
            if(n[f] > 0 ){
                break;
            }

            if(f == 0 || n[f] != n[f-1]){
                twoSumHelper(f , n , ans);
            }
                
        }


        return ans;

    }
};