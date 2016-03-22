// https://leetcode.com/discuss/73762/9ms-short-java-bst-solution-get-answer-when-building-bst
// java solution 9ms
public class Solution {
    class Node {
        Node left, right;
        int val, sum, dup = 1;
        public Node(int v, int s) {
            val = v;
            sum = s;
        }
    }
    public List<Integer> countSmaller(int[] nums) {
        Integer[] ans = new Integer[nums.length];
        Node root = null;
        for (int i = nums.length - 1; i >= 0; i--) {
            root = insert(nums[i], root, ans, i, 0);
        }
        return Arrays.asList(ans);
    }
    private Node insert(int num, Node node, Integer[] ans, int i, int preSum) {
        if (node == null) {
            node = new Node(num, 0);
            ans[i] = preSum;
        } else if (node.val == num) {
            node.dup++;
            ans[i] = preSum + node.sum;
        } else if (node.val > num) {
            node.sum++;
            node.left = insert(num, node.left, ans, i, preSum);
        } else {
            node.right = insert(num, node.right, ans, i, preSum + node.dup + node.sum);
        }
        return node;
    }
}
// https://leetcode.com/discuss/79907/summary-divide-conquer-based-binary-indexed-based-solutions
// http://algobox.org/count-of-range-sum/
class Solution {
public:
    int low;
    int up;
    // vector<int> arr;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        low = lower;
        up = upper;
        // int count = 0;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        long sums[n + 1];
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums[i+1] = sums[i] + nums[i];
        }

        return merge_sort(sums, 0, n + 1);
    }

    int merge_sort(long *sums, int start, int end) {
        if (end - start <= 1) {
            return 0;
        }

        int mid = (start + end)/2;
        int count = merge_sort(sums, start, mid) + merge_sort(sums, mid, end);

        int tmp[end - start];

        int k = mid, j = mid, t = mid;

        // the left and right halvies are sorted
        // for each i, get the indexed that lower <= sums[j] - sums[i] <= upper
        for (int i = start, r = 0; i < mid; i++, r++) {
            // for k, j, t, all the sums are increasing, because they are all referencing right half
            while(k < end && sums[k] - sums[i] < low) {
                k++;
            }
            while(j < end && sums[j] - sums[i] <= up) {
                j++;
            }
            count += j - k;

            // find the elements are smaller then sums[i], and store in tmp for later merge sort
            while(t < end && sums[t] < sums[i]) {
                tmp[r++] = sums[t++];
            }
            tmp[r] = sums[i];

        }

        // merge sort
        for (int i = start; i < t; i++) {
            sums[i] = tmp[i - start];
        }

        return count;
    }


    /*
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) {
                    count++;
                }
            }
        }
        return count;
    }
    */
};



/* java version 15ms
public class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] sums = new long[n + 1];
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
        return countWhileMergeSort(sums, 0, n + 1, lower, upper);
    }

    private int countWhileMergeSort(long[] sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = (start + end) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper)
                  + countWhileMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        long[] cache = new long[end - start];
        for (int i = start, r = 0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) k++;
            while (j < end && sums[j] - sums[i] <= upper) j++;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            count += j - k;
        }
        System.arraycopy(cache, 0, sums, start, t - start);
        return count;
    }
}

*/
