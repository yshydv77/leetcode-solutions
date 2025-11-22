class Solution {
public:
    bool isPalindrome(string& st, int start, int end) {
        while (start < end) {
            if (st[start] != st[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) { 
        int start = 0,
            end = s.size()-1;
        
        while(start < end){
            if(s[start] == s[end]){
                start ++;
                end--;
            }
            else{
                bool cond1 = isPalindrome(s , start+1 , end);
                bool cond2 = isPalindrome(s , start , end-1);
                return cond1 || cond2 ;
            }
        }

        return true;
    }
};