class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // if (m > n){
        //     return minDistance(word2, word1);
        // }
        int d[n+1];
        for(int i = 0; i < n+1; i++){
            d[i] = i;
        }
        int upper_left = 0;
        for (int i = 1; i <= m; i++){
            upper_left = d[0];
            d[0] = i;
            for (int j = 1; j <= n; j++){
                int tmp = d[j];
                // d[i,j] = min(d[i-1,j]+1, d[i,j-1]+1, d[i-1,j-1]+x(i-1)==y(j-1)?0:1);
                //              insert,     delete,     substitute
                if (word1[i-1] == word2[j-1]){
                    d[j] = upper_left;
                }
                else{
                    d[j] = 1 + min(min(d[j-1], d[j]), upper_left);
                }
                upper_left = tmp;
            }
        }
        return d[n];
    }
};