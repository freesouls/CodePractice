class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
        // do initialization if necessary
        // while(!s.empty()) {
        //     s.pop();
        // }

        // while(!mins.empty()) {
        //     mins.pop();
        // }
    }

    void push(int number) {
        // write your code here
        s.push(number);
        if (mins.empty() || number <= mins.top()) {
            mins.push(number);
        }
    }

    int pop() {
        // write your code here
        int num = s.top();
        s.pop();

        if (!mins.empty() && mins.top() == num) {
            mins.pop();
        }
        return num;
    }

    int min() {
        // write your code here
        return mins.top();
    }
};
