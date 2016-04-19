/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for(auto nl: nestedList)
            dq.push_back(nl);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        NestedInteger NI = dq.front();
        dq.pop_front();
        return NI.getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while(dq.size() && !dq.front().isInteger()){
            NestedInteger front = dq.front();
            dq.pop_front();
            vector<NestedInteger> nls = front.getList();
            for(int i = nls.size() - 1; i >= 0; i--){
                dq.push_front(nls[i]);
            }
        }

        if(dq.size() && dq.front().isInteger()) return true;
        return false;
    }

    deque<NestedInteger> dq;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
