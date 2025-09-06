class Solution {
public:
    int minimizedStringLength(string s) {
       sort(s.begin() , s.end());
       string ans = "";
       for(int i = 0 ; i < s.size() ; i++){
        if(ans.empty() ||ans.back() != s[i]){
            ans.push_back(s[i]);
        }
        else{
            continue;
        }
       }
    return ans.size();
    
    }
};