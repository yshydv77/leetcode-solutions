class Solution {
public:
    string expand(string&s , int low , int high){
        // this function is used to expand frm the center
        while(low>=0 && high < s.size() && s[low] == s[high]){
            low--;
            high++;
        }
        return s.substr(low+1,high-low-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans ="";
        for(int i = 0 ; i < n ;i++){
            // odd length
            string odd = expand(s,i,i);
            // even length 
            string even = expand(s,i,i+1);
            if(odd.size() > ans.size()){
                ans=odd;
            }
            if(even.size() > ans.size()){
                ans=even;
            }
        }

        return ans;
    }
};