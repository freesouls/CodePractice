class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = m + n - 1;
        int pa = m - 1;
        int pb = n - 1;
        while(pa >= 0 && pb >= 0){
            nums1[ptr--] = nums1[pa] > nums2[pb] ? nums1[pa--]: nums2[pb--];
        }

        while(pb >= 0){
            nums1[ptr--] = nums2[pb--];
        }
    }
};
