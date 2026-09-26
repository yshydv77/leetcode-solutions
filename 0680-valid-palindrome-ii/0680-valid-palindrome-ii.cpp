class Solution {
public:
    bool checkPalindrome(string &s  , int i , int j ){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int i = 0 ;
        int j = s.size()-1;
        bool ans = false;
        while(i<=j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                bool c1 = checkPalindrome(s,i+1,j);
                bool c2 = checkPalindrome(s,i,j-1);
                bool a = c1 | c2;
                return a;

            }
        }
    return true;
    }
};