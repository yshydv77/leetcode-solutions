class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
          st.push({value , value});
        }
        else{
          pair<int,int>p;
          p.first = value;
          if(value < st.top().second){
            p.second = value;
          }
          else{
            p.second = st.top().second;
          }
          st.push(p);
        }
    }
    
    void pop() {
        if(!st.empty()){
          st.pop();
        }
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
       return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */