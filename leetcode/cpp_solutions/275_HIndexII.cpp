class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        
        int cur = 0;
        while(left <= right) {
            int middle = (right - left)/2 + left;
            if (citations[middle] >= n - middle) {
                // if (n - middle < cur) {
                //     return cur;
                // }
                cur = n - middle;
                right = middle - 1;

            }
            else {
                left = middle + 1;
            }
        }

        return cur;
    }
};
