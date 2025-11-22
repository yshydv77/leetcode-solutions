class Solution {
public:
    void formatString(string &s , string &updatedString){
      for(auto it : s){
        if(isalnum(it)){
          if(isupper(it)){
            updatedString.push_back(tolower(it));
          }
          else{
            updatedString.push_back(it);
          }
        }
      }

    }
    bool isPalindrome(string s) {
      string updatedString = "";
      formatString(s, updatedString);  

      int start = 0;
      int end = updatedString.size()-1;

      while(start <= end){
        if(updatedString[start] != updatedString[end]){
          return false;
        }
        start++;
        end--;

      }
      return true;
    }
};