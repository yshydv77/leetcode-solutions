class Solution {
public:
    int count =0;
    void expand(string &s , int low , int high){
        while(low>=0 && high < s.size() && s[low] == s[high]){
            low--;
            high++;
            count++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();

        for(int i = 0 ; i< n ; i++){
            // oddlength 
            expand(s,i,i);
            expand(s,i,i+1);
        }

        return count ;
    }
};