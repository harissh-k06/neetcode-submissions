class MinStack {
private:
    stack<int> Stack;
    stack<int> minStack;
public:
    MinStack() {

    }
    
    void push(int val) {
        Stack.push(val);
        if (minStack.empty()) minStack.push(val);
        else minStack.push(min(val,minStack.top()));
    }
    
    void pop() {
        Stack.pop();
        minStack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
