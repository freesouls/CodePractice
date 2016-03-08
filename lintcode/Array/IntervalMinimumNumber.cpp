/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class MySegmentTreeNode{
public:
    int start, end;
    int min;
    MySegmentTreeNode* left, *right;
    MySegmentTreeNode(int start_, int end_, int min_): start(start_),
    end(end_), min(min_), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        MySegmentTreeNode* tree = build(A, 0, A.size()-1);

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            Interval q = queries[i];
            res.push_back(query(tree, q.start, q.end));
        }
        return res;
    }

    int query(MySegmentTreeNode* root, int start, int end) {
        if (!root){
            return 0;
        }

        if (start > root->end) {
            return 0;
        }

        if (end < root->start) {
            return 0;
        }

        if (start == root->start && end == root->end) {
            return root->min;
        }

        int mid = (root->start + root->end)/2;

        if (end <= mid) {
            return query(root->left, start, end);
        }

        if (start > mid) {
            return query(root->right, start, end);
        }

        return min(query(root->left, start, mid), query(root->right, mid+1, end));
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
            MySegmentTreeNode* node = new MySegmentTreeNode(start, end, min(left->min, right->min));
            node->left = left;
            node->right = right;

            return node;
        }
    }

};
