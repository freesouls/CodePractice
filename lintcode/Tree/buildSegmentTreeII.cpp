/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        // if (A.size() == 0) {
        //     return NULL;
        // }
        return build(A, 0, A.size()-1);
    }

    SegmentTreeNode * build(vector<int>& A, int start, int end) {
        // write your code here
        if (start > end){
            return NULL;
        }
        else if(start == end){
            SegmentTreeNode* node = new SegmentTreeNode(start, end, A[start]);
            return node;
        }
        else{

            SegmentTreeNode* left = build(A, start, (start + end)/2);
            SegmentTreeNode* right = build(A, (start+end)/2+1, end);
            SegmentTreeNode* node = new SegmentTreeNode(start, end, max(left->max, right->max));
            node->left = left;
            node->right = right;

            return node;
        }
    }

    SegmentTreeNode * build(vector<int>& A, int start, int end) {
        // write your code here
        if (start > end){
            return NULL;
        }
        else if(start == end){
            SegmentTreeNode* node = new SegmentTreeNode(start, end, A[start]);
            return node;
        }
        else{
            int tmp = A[start];
            for (int i = start+1; i <= end; i++) {
                tmp = max(tmp, A[i]);
            }

            SegmentTreeNode* node = new SegmentTreeNode(start, end, tmp);
            node->left = build(A, start, (start + end)/2);
            node->right = build(A, (start+end)/2+1, end);
            return node;
        }
    }
};
