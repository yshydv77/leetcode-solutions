class Solution {
public:
    int fun(int n ){
        int count = 0 ;
        while(n){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {

        vector<int>ans;
        for(int i = 0 ;i <=n;i++){
            ans.push_back(fun(i));
        }
        return ans;
    }
};