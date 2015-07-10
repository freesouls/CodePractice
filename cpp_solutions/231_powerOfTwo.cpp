class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0){
            return false;
        }
        int i = 0;
        for (; i < 32; i++){
            if((n >> i)&1){
                break;
            }
        }
        i++;
        for (; i < 32; i++){
            if((n >> i)&1){
                return false;
            }
        }
        return true;
    }
};
