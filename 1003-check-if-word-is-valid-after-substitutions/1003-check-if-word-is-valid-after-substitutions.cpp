class Solution {
public:
    bool isValid(string s) {
      if(s.size() == 0){
        return true;
      }

      int fnd = s.find("abc");
      if(fnd != string::npos){
        // abc is present in the string
        string left = s.substr(0 , fnd);
        string right = s.substr(fnd + 3 , s.size());
        return isValid(left+right);
      }

      return false;


    }
};