class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1 ){
            return strs[0];
        }

        string ans = "";

        sort(strs.begin() , strs.end());
        string first = strs[0];
        string last = strs[n-1];

        if(first.size() <= last.size()){
            for(int i = 0 ; i < first.size() ; i++){
                if(first[i] == last[i]){
                    ans.push_back(first[i]);
                }
                else{
                    break;
                }
            }
        }

        else{
            for(int i = 0 ; i< last.size() ; i++){
                if(first[i] == last[i]){
                    ans.push_back(first[i]);
                }
                else{
                    break;
                }
            }
        }
    
    return ans;

    }
};