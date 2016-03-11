class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int worst_time = 0;
        for (int i = 0; i < pages.size(); i++) {
            worst_time += pages[i];
        }

        int l = 0;
        int r = worst_time;

        while(l < r) {
            int mid = (l + r)/2;
            if (check(mid, pages, k)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }


    bool check(int time, vector<int>& pages, int k) {
        int cnt = 0;
        int sum = 0;

        for (int i = 0; i < pages.size(); i++) {
            if (sum + pages[i] <= time) {
                sum += pages[i];
            }
            else {
                if (pages[i] <= time) {
                    cnt++;
                    sum = pages[i];
                }
                else{
                    return false;
                }
            }
        }

        if (sum > 0) {
            cnt++;
        }
        return cnt <= k;
    }
};
