class Solution {
public:
    vector<vector<int>>ans;
    void fun(int n , int k ,int i ,  vector<int>temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return ;
        }
        for(int j = i ;  j <= n ;  j++){
            temp.push_back(j);
            fun(n,k,j+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        int i = 1 ;
        vector<int>temp;
        fun(n,k,i,temp);

        return ans;
    }
};