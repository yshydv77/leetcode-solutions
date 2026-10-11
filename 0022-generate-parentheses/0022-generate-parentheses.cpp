class Solution {
public:
    vector<string>ans;
    void helper(int n , string temp , int u , int p){
        if(u == n && p == n){
            ans.push_back(temp);
            return;
        }

        if(u<n){
            temp.push_back('(');
            helper(n,temp,u+1,p);
            temp.pop_back();
        }

        if(p<u){
            temp.push_back(')');
            helper(n,temp,u,p+1);
            temp.pop_back();
        }


        return ;


    }
    vector<string> generateParenthesis(int n) {
        if(n==1){
            return {"()"};
        }
        string temp = "";
        int u = 0;
        int p = 0 ;
        helper(n,temp,u,p);
        return ans;
    }
};