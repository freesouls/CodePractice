/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto nl: nestedList)
            dq.push_back(nl);
    }

    int next() {
        NestedInteger NI = dq.front();
        dq.pop_front();
        return NI.getInteger();
    }

    bool hasNext() {
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

private:
    deque<NestedInteger> dq;
};

class NestedIterator {
public:
    deque<int> list;
    NestedIterator(vector<NestedInteger> &nestedList) {
        push_to_list(list, nestedList);
    }

    void push_to_list(deque<int>& list, vector<NestedInteger>& nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            }
            else {
                push_to_list(list, nestedList[i].getList());
            }
        }
    }

    int next() {
        int res = list.front();
        list.pop_front();
        return res;
    }

    bool hasNext() {
        return !list.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
