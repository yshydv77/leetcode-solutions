class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.empty())
            return 0;
        int ans = 0;
        stack<char> st;
        for(char ch : s){
          if(ch == '(')
            st.push(ch);
          else{
            //)
            if(!st.empty() && st.top() == '(')
              st.pop();
            else
              ans++;
          }
        }

        return ans+st.size();
        
    }
};