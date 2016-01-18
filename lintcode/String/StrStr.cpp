class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (target == NULL || source == NULL) {
            return -1;
        }

        int i = 0;
        int j = 0;
        while (*(source+i) != '\0' && *(target+j) != '\0' ) {
            if (source[i] == target[j]){
                i++;
                j++;
            }
            else{
                i = i - j + 1;
                j = 0;
            }
        }
        // it is the same as *(target+j) == 0
        if (*(target+j)=='\0') {
            return i - j;
        }

        return -1;
    }

    int strStr1(const char *source, const char *target) {
        // write your code here
        if (target == NULL || source == NULL) {
            return -1;
        }

        int sLen = strlen(source);
        int tLen = strlen(target);

        int i = 0;
        int j = 0;
        while (i < sLen && j < tLen ) {
            if (source[i] == target[j]){
                i++;
                j++;
            }
            else{
                i = i - j + 1;
                j = 0;
            }
        }

        if (j == tLen) {
            return i - j;
        }

        return -1;
    }
};
