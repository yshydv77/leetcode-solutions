class Solution {
public:
    int palindrome(string s , int i , int j){
        int count = 0 ;
        while(i>=0 && j < s.size() && s[i] == s[j]){
            // if s[i] is going to be equal to s[j] then only it is going to be the palindrome 
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0 ;
        for(int center = 0 ; center < s.size() ; center++){
            // for odd length
            int i = center;
            int j = center;

            int oddLengthPalindromeCount = palindrome(s , i ,j);
            i = center;
            j = center+1;
            int evenLengthPalindromeCount = palindrome(s,i,j);

            count += evenLengthPalindromeCount+oddLengthPalindromeCount;
        }
        return count;
    }
};