class Solution {
public:
    int minSwaps(string s) {
        if(s.size() & 1) return -1;
        int ans = 0 ;
        stack<char>st;
        for(char ch : s){
          if(ch == '[') st.push(ch);
          else{
            if(!st.empty() && st.top() == '[') st.pop();
            else st.push(ch);
          }
        }

        while(!st.empty()){
          char second = st.top();st.pop();
          char first = st.top(); st.pop();
          if(first == second) ans++;
          else ans+=2;
        }

        return (ans/2);
    }
};