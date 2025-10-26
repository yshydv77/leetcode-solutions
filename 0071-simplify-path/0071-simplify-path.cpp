class Solution {
public:
    void buildStack(string &ans ,  stack<string>&st){
      if(st.empty()){
        return ;
      }
      string minPath = st.top();
      st.pop();
      buildStack(ans , st);
      ans+=minPath;
    }
    string simplifyPath(string path) {
        int i = 0;
        stack<string>st;

        while(i < path.size()){
          int start = i;
          int end = i+1;
          while(end < path.size() && path[end] != '/'){
            end++;
          }
          string miniPath = path.substr(start ,end - start );
          i = end;
          if(miniPath == "/." || miniPath == "/"){
            continue;
          }
          else if(miniPath != "/.."){
            
            st.push(miniPath);
          }
          else{
            if(st.empty()) continue;
            else st.pop();
          }

        }

        string ans = st.empty() ? "/" : "";

        buildStack(ans , st);


        return ans;

    }
};