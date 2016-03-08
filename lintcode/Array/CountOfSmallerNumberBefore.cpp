class Node {
public:
    int index;
    int value;
    Node(int ind, int val): index(ind), value(val){}
};

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<Node* > arr;
    vector<Node* > tmp;
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        arr.clear();
        for (int i = 0; i < A.size(); i++) {
            arr.push_back(new Node(i, A[i]));
        }

        tmp.resize(A.size(), NULL);
        vector<int> res(A.size(), 0);
        merge_sort(res, 0, A.size()-1);
        return res;
    }

    void merge_sort(vector<int> & res, int start, int end) {
        if (start >= end) {
            return ;
        }

        int mid = (start + end)/2;

        merge_sort(res, start, mid);
        merge_sort(res, mid+1, end);

        int i = start;
        int j = mid + 1;
        int p = 0;
        while(i <= mid && j <= end) {
            if (arr[i]->value < arr[j]->value) { // <= is wrong
                tmp[p++] = arr[i++];
            }
            else{
                res[arr[j]->index] += (i-start);
                tmp[p++] = arr[j++];
            }
        }

        while(i <= mid) {
            tmp[p++] = arr[i++];
        }

        while( j <= end) {
            res[arr[j]->index] += mid + 1 - start; // or += i-start
            tmp[p++] = arr[j++];
        }

        for (int i = start; i <= end; i++) {
            arr[i] = tmp[i-start];
        }
    }
};
