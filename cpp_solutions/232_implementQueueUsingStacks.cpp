class Queue {
    stack<int> a;
    stack<int> b;
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        b.pop();
    }

    // Get the front element.
    int peek(void) {
        if (b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty() && b.empty();
    }
};
