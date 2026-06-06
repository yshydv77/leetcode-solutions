class Solution {
public:
bool match(char a , char b){
    if((a == '(' && b == ')') ||( a == '{' && b == '}') || (a == '[' &&  b ==  ']') ){
        return true;
    }
    return false;
}
bool isValid(string s) {
    // stack ka question isliye hai because meko recent most element ka use karna hai 
    stack<char>st;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else {
            // iska matlab ye hai ki yaha par closing bracket aagaya yaa phir mera stack hi empty hai 
            if(st.empty()){
                return false;
            }
            else{
                // stack is not empty now i have to check wheter the stack topmost bracket mathc the current bracket or not 
                if(match(st.top() , s[i]) == false){
                   return false;
                }
                else{
                    st.pop();
                }
                
            }
        }
    }

    return st.empty();
}
};