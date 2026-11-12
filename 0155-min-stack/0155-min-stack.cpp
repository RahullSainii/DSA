class MinStack {
    private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
       
        long long x = value;

        if (st.empty()) {
            st.push(x);
            mini = x;
        }
        else if (x >= mini) {
            st.push(x);
        }
        else {
            // Encode the previous minimum
            st.push(2LL * x - mini);
            mini = x;
        }
    
    }
    
    void pop() {
        if (st.top() < mini) {
            // Restore the previous minimum
            mini = 2LL * mini - st.top();
        }

        st.pop();
    }
    
    int top() {
        if (st.top() < mini) {
            return (int)mini;
        }

        return (int)st.top();
    }
    
    int getMin() {
         return (int)mini;
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