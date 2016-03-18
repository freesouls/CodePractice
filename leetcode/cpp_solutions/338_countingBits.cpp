class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnts(num + 1, 0);
        int pre_index = 0;
        for (int i = 1; i <= num; i++ ) {
            // if (i&1) {
            //     cnts[i] = cnts[pre_index] + 1;
            // }
            // else{
            //     cnts[i] = cnts[++pre_index];
            // }

            if (i % 2 == 0) {
                // cnts[i] = cnts[i>>1];
                cnts[i] = cnts[i/2];
            }
            else {
                // cnts[i] = cnts[i>>1] + 1;
                cnts[i] = cnts[i/2]+1;
            }

        }
        return cnts;
    }
};
