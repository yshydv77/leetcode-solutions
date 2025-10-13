class Solution {
public:
    bool check(char current , char top){
        if((top == '(' && current == ')') || (top == '{' && current == '}') || (top == '[' && current == ']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        
        if(s.size() == 0){
            return true;
        }

        stack<char>st;
        for(int i = 0 ; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                bool ans = check(ch ,  st.top());
                if(!ans){// condition for mismatch between the parenthesis 
                    return false;
                }
                st.pop();
            }
        }

        if(!st.empty()){
            return false;
        }
        return true;
    }
};