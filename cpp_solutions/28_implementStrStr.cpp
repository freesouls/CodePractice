// TODO: KMP algorithm
// http://blog.csdn.net/v_july_v/article/details/7041827
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.size();
        int nLen = needle.size();
        if (hLen < nLen){
            return -1;
        }
        int i = 0;
        int j = 0;

        while(i < hLen && j < nLen){
            if (haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                i = i - j + 1;
                j = 0;
            }
        }

        if (j == nLen){
            return i - j;
        }
        else{
            return -1;
        }
    }
};
