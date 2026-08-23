class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int res = 0 ;
        int i = 0 ;
        int  j = 0 ;
        int g_size = g.size(); // greed of n childrens 
        int s_size = s.size(); // size of n cookies 

        while(i < g_size && j < s_size){
            if(s[j] >= g[i]){
                // greed is statisfied
                res++;
                i++;
                j++;
                // because the greed of the children is satisfied

            }
            else{
                // if the greed of the children is not satisfied then we have to move to the next big cookie to find out whether we can satisfy the grid of that children or not 
                j++;
            }
        }
        
        return res;
    }
};