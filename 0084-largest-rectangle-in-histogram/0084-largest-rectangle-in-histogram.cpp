class Solution {
public:

    // is question mein we cannot increase the height of that particular bar we can only increase the width for that particular bar vo bhi tab jab adjacent bar same yaa usse zyadda height ke ho 
    void nextSmaller(vector<int>& arr , vector<int>& next){ 
        stack<int>st; // in this question inside stack we are going to store the index of the element in the stack 
        st.push(-1);
        
        for(int i = arr.size()-1 ; i>=0 ; i-- ){
            int element = arr[i];
            while(st.top() != -1 && arr[st.top()] >= element){
                st.pop();
            }

            // yaha par aagay iska matlab hai ki stack ka top element chota hai humare current element se
            next.push_back(st.top());
            st.push(i);// because for width we onlly want the index not the actual value at that particular index
        }


    }

    void prevSmaller(vector<int>& arr , vector<int>& prev){
        stack<int>st; // in this question inside stack we are going to store the index of the element in the stack 
        st.push(-1);
        
        for(int i = 0 ; i < arr.size() ; i++){
            int element = arr[i];
            while(st.top() != -1 && arr[st.top()] >= element){
                st.pop();
            }

            prev.push_back(st.top());
            st.push(i);
        }


    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next;
        vector<int>prev;
        nextSmaller(heights , next);
        reverse(next.begin() , next.end());
        prevSmaller(heights , prev);
        for(int i = 0 ; i < next.size() ;i++){
            if(next[i] == -1){
                next[i] = heights.size();
            }
        }

        vector<int>area;
        for(int i = 0 ; i < heights.size() ;i++){
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            area.push_back(width * height);
        }

        int maxArea = INT_MIN;
        for(int i = 0 ; i < area.size() ; i++){
            if(area[i] > maxArea){
                    maxArea = area[i];
            }
        }


        return maxArea;
    }
};