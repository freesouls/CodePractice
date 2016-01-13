class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    void push(int x) {
        s.push(x);
        if (mins.empty() || mins.top() >= x){
            mins.push(x);
        }
    }

    void pop() {
        int x = s.top();
        s.pop();
        if (!mins.empty() && mins.top() == x){
            mins.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
};
