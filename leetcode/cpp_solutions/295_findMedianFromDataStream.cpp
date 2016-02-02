class MedianFinder {
public:
    // priority_queue default is max_heap
    priority_queue<int> small_half, large_half;
    // Adds a number into the data structure.
    void addNum(int num) {
        small_half.push(num); // max heap
        large_half.push(-small_half.top()); // use negative for min heap
        small_half.pop();
        if (small_half.size() < large_half.size()) {
            small_half.push(-large_half.top());
            large_half.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small_half.size() > large_half.size() ? small_half.top() : (small_half.top() - large_half.top())/2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
