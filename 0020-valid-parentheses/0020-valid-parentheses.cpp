class Solution {
public:
    bool check_brackets(char s , char e){
      if((s == '(' && e == ')') || (s=='{' && e=='}') || (s=='[' && e==']'))
        return true;
      else 
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for (auto it : s){
       
          if(it == '(' || it == '{' || it == '[')
            st.push(it);
          else{
            if(!st.empty() && check_brackets(st.top() , it))
              st.pop();
            else
              return false;
          }
        }

        return st.empty();
    }
};