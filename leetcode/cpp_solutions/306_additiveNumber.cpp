class Solution {
private:
    string add(string num1, string num2){
        string result("");
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while (i >= 0 && j >= 0) {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            result = (char)('0' + (sum%10)) + result;
            carry = sum/10;
            i--;
            j--;
        }

        while ( i>= 0 ) {
            int sum = num1[i] - '0' + carry;
            result = (char)('0' + (sum%10)) + result;
            carry = sum/10;
            i--;
        }

        while ( j>= 0 ) {
            int sum = num2[j] - '0' + carry;
            result = (char)('0' + (sum%10)) + result;
            carry = sum/10;
            j--;
        }

        if (carry) {
            result = "1" + result;
        }
        return result;
    }
    bool valid(string num1, string num2, string remain){
        string sum = add(num1, num2);
        if(remain.length() < sum.length()){
            return false;
        }
        if(remain.compare(sum) == 0){
            return true;
        }
        if(remain.substr(0, sum.length()).compare(sum) != 0){
            return false;
        }
        return valid(num2, sum, remain.substr(sum.length()));
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.length() < 3){
            return false;
        }
        for(int len1 = 1; len1 <= num.length()/2; len1++){
            for(int len2 = 1; len2 <= num.length()/2; len2++){
                string num1 = num.substr(0, len1);
                string num2 = num.substr(len1, len2);
                if (num2[0] == '0' && len2 > 1) {
                    continue;
                }
                string remain = num.substr(len1+len2);
                if (remain[0] == '0' && remain.length() > 1) {
                    continue;
                }
                if(valid(num1, num2, remain)){
                    return true;
                }
            }
        }
        return false;
    }
};
