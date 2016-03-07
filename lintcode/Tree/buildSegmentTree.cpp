/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end){
            return NULL;
        }
        else if(start == end){
            SegmentTreeNode* node = new SegmentTreeNode(start, end);
            return node;
        }
        else{
            SegmentTreeNode* node = new SegmentTreeNode(start, end);
            node->left = build(start, (start + end)/2);
            node->right = build((start+end)/2+1, end);
            return node;
        }
    }
};
