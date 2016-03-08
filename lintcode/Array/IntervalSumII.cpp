class MySegmentTreeNode{
public:
    int start, end;
    long long sum;
    MySegmentTreeNode* left, *right;
    MySegmentTreeNode(int start_, int end_, long long sum_): start(start_),
    end(end_), sum(sum_), left(NULL), right(NULL) {}
};

class Solution {
public:
    /* you may need to use some attributes here */

    // vector<int> ints;
    // vector<long long> sums;
    MySegmentTreeNode* tree;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        tree = build(A);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return query(tree, start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modify(tree, index, value);
    }

    long long query(MySegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root){
            return INT32_MIN;
        }

        if (start > root->end) {
            return INT32_MIN;
        }

        if (end < root->start) {
            return INT32_MIN;
        }

        if (start == root->start && end == root->end) {
            return root->sum;
        }

        int mid = (root->start + root->end)/2;

        if (end <= mid) {
            return query(root->left, start, end);
        }

        if (start > mid) {
            return query(root->right, start, end);
        }

        return query(root->left, start, mid) + query(root->right, mid+1, end);
    }

    MySegmentTreeNode * build(vector<int>& A) {
        // write your code here
        // if (A.size() == 0) {
        //     return NULL;
        // }
        return build(A, 0, A.size()-1);
    }

    MySegmentTreeNode * build(vector<int>& A, int start, int end) {
        // write your code here
        if (start > end){
            return NULL;
        }
        else if(start == end){
            MySegmentTreeNode* node = new MySegmentTreeNode(start, end, A[start]);
            return node;
        }
        else{

            MySegmentTreeNode* left = build(A, start, (start + end)/2);
            MySegmentTreeNode* right = build(A, (start+end)/2+1, end);
            MySegmentTreeNode* node = new MySegmentTreeNode(start, end, left->sum + right->sum);
            node->left = left;
            node->right = right;

            return node;
        }
    }

    void modify(MySegmentTreeNode *root, int index, int value) {
        // write your code here
        if (!root){
            return;
        }

        if (index > root->end || index < root->start) {
            return;
        }

        if (index == root->start && index == root->end) {
            root->sum = value;
            return;
        }

        int mid = (root->start + root->end)/2;
        if (index <= mid) {
            modify(root->left, index, value);
        }
        else {
            modify(root->right, index, value);
        }
        root->sum = root->left->sum + root->right->sum;
    }
};
