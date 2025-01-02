class MinStack {
public:
    vector<vector<int>> st;
    int min_val;
    MinStack() {    
        min_val = INT_MAX;
    }
    
    void push(int val) {
        vector<int> temp;
        if(min_val>val)
            min_val = val;
        temp.push_back(val);
        temp.push_back(min_val);
        st.push_back(temp);
    }
    
    void pop() {
        st.pop_back();
        if(st.empty()){
            min_val = INT_MAX;
        }
        else
            min_val = st.back()[1];
    }
    
    int top() {
        return st.back()[0];
    }
    
    int getMin() {
        return st.back()[1];
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