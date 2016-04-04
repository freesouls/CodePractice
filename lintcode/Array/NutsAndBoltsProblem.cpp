/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        if(nuts.empty() || bolts.empty()) return;
        int n = nuts.size(), m = bolts.size();
        if(m!=n) return;
        quickSort(nuts,bolts,compare, 0, n-1);
    }
    void quickSort(vector<string>& nuts, vector<string>& bolts, Comparator compare, int start, int end){
        if(start >= end) return;
        int idx = partition(nuts,bolts[start], compare, start, end);
        partition(bolts, nuts[idx], compare, start, end);

        quickSort(nuts, bolts, compare, start, idx-1);
        quickSort(nuts, bolts, compare, idx+1, end);
    }
    int partition(vector<string>& NorB, string pivot, Comparator compare, int start, int end){
        int m = start;// m indicates the actual position of pivot.
        for(int i = start+1; i<=end; ++i){
            if(compare.cmp(pivot, NorB[i]) == 1 || compare.cmp(NorB[i],pivot) == -1){
                swap(NorB[++m],NorB[i]);
            }else if(compare.cmp(pivot,NorB[i]) == 0 || compare.cmp(NorB[i], pivot) == 0){
                swap(NorB[start],NorB[i]);
                --i;
            }
        }
        swap(NorB[m], NorB[start]);
        return m;
    }
};


/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        if(nuts.empty() || bolts.empty()) return;
        int n = nuts.size(), m = bolts.size();
        if(m!=n) return;
        quickSort(nuts,bolts,compare, 0, n-1);
    }
    void quickSort(vector<string>& nuts, vector<string>& bolts, Comparator compare, int start, int end){
        if(start >= end) return;
        int idx = partition(nuts,bolts[start], compare, start, end, true);
        partition(bolts, nuts[idx], compare, start, end, false);

        quickSort(nuts, bolts, compare, start, idx-1);
        quickSort(nuts, bolts, compare, idx+1, end);
    }
    int partition(vector<string>& NorB, string pivot, Comparator compare, int start, int end, bool flag){
        int m = start;// m indicates the actual position of pivot.
        if (flag) {
            for(int i = start+1; i<=end; ++i){
                if(compare.cmp(NorB[i],pivot) == -1){
                    swap(NorB[++m],NorB[i]);
                }else if(compare.cmp(NorB[i], pivot) == 0){
                    swap(NorB[start],NorB[i]);
                    --i;
                }
            }
        }
        else {
            for(int i = start+1; i<=end; ++i){
                if(compare.cmp(pivot, NorB[i]) == 1){
                    swap(NorB[++m],NorB[i]);
                }else if(compare.cmp(pivot,NorB[i]) == 0){
                    swap(NorB[start],NorB[i]);
                    --i;
                }
            }
        }

        swap(NorB[m], NorB[start]);
        return m;
    }
};
