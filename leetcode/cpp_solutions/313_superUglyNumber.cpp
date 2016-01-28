class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        int primes_index[k];
        int primes_factor[k];

        for (int i = 0; i < k; i++) {
            primes_index[i] = 0;
            primes_factor[i] = primes[i];
        }
        int res[n];
        res[0] = 1;
        int i = 1;
        while (i < n) {
            int min_value = primes_factor[0];
            for (int j = 1; j < k; j++) {
                min_value = std::min(min_value, primes_factor[j]);
            }
            res[i] = min_value;
            for (int j = 0; j < k; j++) {
                if (min_value == primes_factor[j]) {
                    primes_factor[j] = primes[j]*res[++primes_index[j]];
                }
            }
            i++;
        }

    //    priority_queue<Node, vector<Node>, NodeComp> min_heap;
    //    for (int i = 0; i < k; i++) {
    //        min_heap.push(Node(primes[i], i));
    //    }
       //
    //    int i = 1;
    //    while(i < n) {
    //        Node min_node = min_heap.top();
    //        res[i] = min_node.val;
    //        // pop all the nodes' value = min_node.val
    //        // and reset the primes_index
    //        min_heap.pop();
    //        int index = min_node.index;
    //        min_node.val = primes[index]*res[++primes_index[index]];
    //        min_heap.push(min_node);
    //        i++;
    //    }
        return res[n-1];
    }
};
