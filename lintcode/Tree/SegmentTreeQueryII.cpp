/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > end) {
            return 0;
        }

        if (root->start > end || root->end < start) {
            return 0;
        }

        start = max(start, root->start);
        // handle cases like query(0, 16), while the tree only constructed from an array[0:14]
        end = min(end, root->end);

        if (root->start == start && root->end == end) {
            return root->count;
        }

        int mid = (root->start + root->end)/2;

        if (end <= mid) {
            return query(root->left, start, end);
        }
        if (start > mid){
            return query(root->right, start, end);
        }

        return query(root->left, start, mid) + query(root->right, mid+1, end);
    }
};
