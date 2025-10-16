class Solution {
public:
    void nge(vector<int>&arr2 , vector<int>&next){
        stack<int>st;
        st.push(-1);

        for(int i = arr2.size()-1 ; i >= 0 ; i--){
            int ele = arr2[i];
            while(!st.empty() &&st.top() <= ele){
                st.pop();
            }

            next[i] = (st.empty()) ? -1 :  st.top();
            st.push(ele);
        }
    }
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        vector<int>next(arr2.size(), -1);
        nge(arr2 , next);

        vector<int>ans;

        for(int i = 0 ; i < arr1.size() ; i++){
            auto it = find(arr2.begin() , arr2.end() , arr1[i]);
            if(it != arr2.end()){

            auto index = distance(arr2.begin() , it);
            auto ngeAtI = next[index];
            ans.push_back(ngeAtI);
            }
            else{
                ans.push_back(-1);
            }

        }

        return ans;
    }
};