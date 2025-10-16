class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int>p;
        p.first = val;
        if(st.empty()){
            p.second = val;
        }
        else{
            if(st.back().second > val){
                // matlab mere minimum element change ho gaya hai and new minimum element mera ye value hoga
                p.second = val;
            }
            else{
                p.second = st.back().second;
            }
        }

        st.push_back(p);
    }
    
    void pop() {
        if(st.empty()){
           
        }
        st.pop_back();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.back().first;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }

        return st.back().second;
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