class Solution {
public:
string decodeString(string s) {
  // because we want the most recent element that's why we are using stack here
  stack<string> st;
  for(int i = 0 ; i < s.size() ; i++){
    if(s[i] != ']'){
      // matlab s[i] yaa toh alphabet hai yaa phir s[i] '['
      st.push(string(1,s[i]));
    }
    else{
      //s[i] == ']'
      string word = "";
      while(!st.empty() && st.top() != "["){
        word += st.top();
        st.pop();
      }

      if(st.top() == "["){
        st.pop();
      }

      string num = "";
      while(!st.empty() && isdigit(st.top()[0])){
        num += st.top();
        st.pop();
      }
      reverse(num.begin() , num.end());

      int times = stoi(num);
      string final = "";
      while(times--){
        final += word;
      }
      st.push(final);
    }
  }



  string ans = "";
  while(!st.empty()){
    ans+= st.top();
    st.pop();
  }

  reverse(ans.begin() , ans.end());
  return ans;
}
};