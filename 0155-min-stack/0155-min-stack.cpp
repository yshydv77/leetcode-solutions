class MinStack {
public:
    vector<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if(st.size() != 0){
            st.pop_back();   
        }
    }
    
    int top() {
        if(st.size()){
            return st.back();
        }
        return -1;
    }
    
    int getMin() {
        if(st.size()){
            return *(min_element(st.begin() , st.end()));
        }

        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */