class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(ans.empty() || s[i] != '*'){
                ans.push_back(s[i]);
            }
            else{
                // jaise hi vo star ke equal ho gaya toh mujhe pop back karvana padega
                ans.pop_back();
            }
        }
        return ans;
    }
};