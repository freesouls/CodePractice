class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m+n)%2) { // is odd
            return findKth(nums1, 0, m, nums2, 0, n, (m+n)/2+1);
        }
        else{
            return (findKth(nums1, 0, m, nums2, 0, n, (m+n)/2) + findKth(nums1, 0, m, nums2, 0, n, (m+n)/2+1))/2.0;
        }
    }

    int findKth(vector<int>& nums1, int left1, int m,
                   vector<int>& nums2, int left2, int n, int k) {
        if (m > n) {
            return findKth(nums2, left2, n, nums1, left1, m, k);
        }

        if (m == 0) {
            return nums2[left2+k-1];
        }

        if (k == 1) {
            return std::min(nums1[left1], nums2[left2]);
        }

        int pa = std::min(k/2, m);
        int pb = k - pa;

        if (nums1[left1 + pa-1] > nums2[left2 + pb - 1]) {
            return findKth(nums1, left1, m, nums2, left2+pb, n-pb, k-pb);
        }
        else if (nums1[left1 + pa-1] < nums2[left2+pb-1]) {
            return findKth(nums1, left1+pa, m-pa, nums2, left2, n, k-pa);
        }
        else {
            return nums1[left1+pa-1];
        }
    }
};

using namespace std;

/*
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. The overall run time
complexity should be O(log (m+n)).
*/

int min(int a, int b)
{
	return a < b ? a : b;
}

class Solution {
public:
	double findKth(int a[], int m, int b[], int n, int k)
	{
		if (m>n)
		{
			return findKth(b, n, a, m, k);
		}
		if (m == 0)
		{
			return (double)b[k - 1];
		}
		if (k == 1)
		{
			return (double)min(a[0], b[0]);
		}

		int pa = min(k / 2, m);
		int pb = k - pa;

		if (a[pa - 1] < b[pb - 1])
		{
			return findKth(a + pa, m - pa, b, n, k - pa);
		}
		else if (a[pa - 1] > b[pb - 1])
		{
			return findKth(a, m, b + pb, n - pb, k - pb);
		}
		else
		{
			return (double)a[pa - 1];
		}

	}

	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		if ((m + n) % 2 == 1) // use (m+n) & 0x1 may be faster
		{
			return findKth(A, m, B, n, (m + n) / 2 + 1);
		}
		else
		{
			return (findKth(A, m, B, n, (m + n) / 2)
				+ findKth(A, m, B, n, (m + n) / 2 + 1)) / 2;
		}
	}
};

int main()
{
	Solution *s = new Solution();
	int A[5] = { 1, 2, 6, 7, 8 };
	int B[3] = { 3, 4, 5 };
	int c = (3 + 4) / 2;
	double b = s->findMedianSortedArrays(A,5,B,3);
	return 0;
}
