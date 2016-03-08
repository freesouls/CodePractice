class SegmentTreeNodeMy {
  public:
      int start, end, max, min;
      SegmentTreeNodeMy *left, *right;
      SegmentTreeNodeMy(int start, int end, int max, int min) {
          this->start = start;
          this->end = end;
          this->max = max;
          this->min = min;
          this->left = this->right = NULL;
      }
 };


class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
     vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
         // write your code here
         if (A.size() == 0) {
             return vector<int>(queries.size(), 0);
         }

         sort(A.begin(), A.end());
         vector<int> res;
         for (int i = 0; i < queries.size(); i++) {
             int q = queries[i];
             int num = countSmaller(q, A);
             res.push_back(num);
         }
         return res;
     }

     int countSmaller(int q, vector<int> &A) {
         int start = 0;
         int end = A.size()-1;
         while(start < end) {
             int mid = (start + end)/2;
             if (A[mid] < q){
                 start = mid + 1;
             }
             else if (A[mid] > q) {
                 end = mid - 1;
             }
             else{
                 while(A[mid] == q){
                     mid--;
                 }
                 return mid + 1;
             }
         }

         if (q < A[start]) {
             return start;
         }

         while(A[start]==q){
             start--;
         }
         return start + 1;
     }

    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here

        SegmentTreeNodeMy* root = build(A);

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {

            int num = countSmaller(root, queries[i]);
            res.push_back(num);
        }
        return res;
    }


    int countSmaller(SegmentTreeNodeMy* root, int q) {
        if (!root) {
            return 0;
        }
        if (root->max < q) {
            return root->end - root->start + 1;
        }
        else if (root->min >= q) {
            return 0;
        }
        else {
            return countSmaller(root->left, q) + countSmaller(root->right, q);
        }
    }

    SegmentTreeNodeMy * build(vector<int>& A) {
        return build(A, 0, A.size()-1);
    }

    SegmentTreeNode * build(vector<int>& A, int start, int end) {
        // write your code here
        if (start > end){
            return NULL;
        }
        else if(start == end){
            SegmentTreeNode* node = new SegmentTreeNodeMy(start, end, A[start], A[start]);
            return node;
        }
        else{

            SegmentTreeNode* left = build(A, start, (start + end)/2);
            SegmentTreeNode* right = build(A, (start+end)/2+1, end);
            SegmentTreeNode* node = new SegmentTreeNodeMy(start, end, max(left->max, right->max), min(left->min, right->min));
            node->left = left;
            node->right = right;

            return node;
        }
    }
};
