class Solution {
public:
    string formatter(string &s){
        string st;
        for(int i = 0 ; i < s.size() ; i++){
            if(isalnum(s[i])){
                st.push_back(tolower(s[i]));
            }
        }
        return st;
    }
    bool isPalindrome(string s) {
        string st = formatter(s);
        string rev = st;
        int i = 0 ;
        int j = st.size()-1;
        while(i<j){
            swap(st[i] , st[j]);
            i++;
            j--;
        }

        return (rev == st);
    }
};