class Solution {
public:
string removeDuplicates(string s, int k) {
    stack<pair<char , int>>st;
    string ans;
    vector<int>hashmap(26);
    for(int i = 0 ; i < s.size() ; i++){

        if(st.empty()){
            
            st.push({s[i] , 1});
        }
        else{
            if(st.top().first == s[i]){
                if(st.top().second == k-1){
                    int j = k-1;
                    while(!st.empty() && j--){
                        st.pop();
                    }
                }
                else{
                    int count = st.top().second + 1;
                    st.push({s[i] , count});
                }
            }
            else{
                st.push({s[i] , 1});
            }
        }
    }

    while(!st.empty()){
        ans.push_back(st.top().first);
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
};