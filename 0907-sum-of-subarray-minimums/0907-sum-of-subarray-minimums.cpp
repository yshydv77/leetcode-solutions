class Solution {
public:

    void nextSmallerElement(vector<int>&arr , vector<int>&next){
        stack<int>st;
        st.push(-1);
        // whenver we do this type of question isme mujhe index ka hi kaam hota hai
        // jab hum next smaller element find out karte hai tab mein right side se start krta hu find out karna
        for(int i = arr.size()-1 ; i>=0 ; i--){
            int ele = arr[i];
            while(st.top()!= -1 && arr[st.top()] >= ele ){
                st.pop();
            }

            next[i] = st.top();
            st.push(i);
        }
    }
    void prevSmallerElement(vector<int>&arr , vector<int>&prev){
        stack<int>st;
        st.push(-1);

        for(int i = 0 ; i < arr.size() ; i++){
            int ele = arr[i];

            while(st.top() != -1 && arr[st.top()] > ele){
                st.pop();
            }

            prev[i] = st.top();
            st.push(i);
        }
    }


    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        vector<int>next(arr.size() , -1);
        vector<int>prev(arr.size() , -1);

        nextSmallerElement(arr,next);
        prevSmallerElement(arr, prev);

        long long int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int nextI = (next[i] == -1) ? arr.size() : next[i];
            int prevI = prev[i];

            int left = i - prevI;
            int right = nextI - i ;

            // left and right are the values which show us that including this ith element how many subarrays we can make so that the ith element is the minimum element in that subarray 

            long long int no_of_times = (left * right ) % mod;
            long long int total = (arr[i] * no_of_times) % mod;
            ans = (ans + total) % mod;


        }

        return ans;

    }
};