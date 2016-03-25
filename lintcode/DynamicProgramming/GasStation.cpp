class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    /*
    To solve this problem, we need to understand and use the following 2 facts:
    1) if the sum of gas >= the sum of cost, then the circle can be completed.
    2) if A can not reach C in a the sequence of A-->B-->C, then B can not make it either.
    If gas[A] < cost[A], then A can not even reach B.
    So to reach C from A, gas[A] must >= cost[A].
    Given that A can not reach C, we have gas[A] + gas[B] < cost[A] + cost[B],
    and gas[A] >= cost[A],
    Therefore, gas[B] < cost[B], i.e., B can not reach C.
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int sum = 0;
        int total = 0;
        int k = 0;
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            //小于0就只可能在i + 1或者之后了
            if(sum < 0) {
                k = i + 1;
                sum = 0;
            }
            total += gas[i] - cost[i];
        }

        if(total < 0) {
            return -1;
        } else {
            return k;
        }
    }
};
