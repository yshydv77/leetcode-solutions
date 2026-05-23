class Solution {
public:
    string onlyText(string s) {
      string a;
      for (int i = 0; i < s.size(); i++) {
        if(a.size() == 0 && s[i] == '#'){
          a = "";
        }
        else if (s[i] == '#') {
            a.pop_back();
        } else {
            a.push_back(s[i]);
        }
      }
      return a;
    }
    bool backspaceCompare(string s, string t) {

      string a = onlyText(s);
      string b = onlyText(t);
      
      return (a==b);
           
    }
    };