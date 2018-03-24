class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        ;
    }
    
    void push(int x) {
        s.push(make_pair(x, min(x, s.empty() ? INT_MAX : s.top().second)));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.empty() ? INT_MIN : s.top().first;
    }
    
    int getMin() {
        return s.empty() ? INT_MAX : s.top().second;
    }
private:
    stack<pair<int,int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
