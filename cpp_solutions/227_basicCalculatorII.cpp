class Solution {
public:
    inline int level(char a){
        if (a == '+' || a == '-'){
            return 0;
        }
        else{
            return 1;
        }
    }

    int calculate(string s) {
        int res;
        stack<int> nums;
        stack<char> op;
        int flag = 1;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        if (s[i] == '-'){
            flag = -1; // check the leading number is negative
            i++;
        }
        int number = 0;
        while (i < s.length()  &&  s[i] >= '0'){
            number = 10 * number + s[i++] - '0'; 
        }
        nums.push(number*flag); // get the leading number
                
        for(; i < s.length(); i++){
            if (s[i] >= '0'){
                int number = 0;
                while (i < s.length()  &&  s[i] >= '0')
                    number = 10 * number + s[i++] - '0';
                i--;
                nums.push(number);
            }
            else if(s[i] == ' '){
                continue;
            }
            else{

                if (op.empty()){
                    op.push(s[i]);
                }
                else{
                    while(!op.empty() && level(op.top()) >= level(s[i])){
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        switch(op.top()){
                            case '+':
                                nums.push(a+b);
                                break;
                            case '-':
                                nums.push(a-b);
                                break;
                            case '*':
                                nums.push(a*b);
                                break;
                            case '/':
                                nums.push(a/b);
                                break;
                        }
                        op.pop();
                    }
                    op.push(s[i]);
                }
            }
        }
        if (nums.empty()){
            return 0;
        }
        else{
            while(!op.empty()){
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                switch(op.top()){
                    case '+':
                        nums.push(a+b);
                        break;
                    case '-':
                        nums.push(a-b);
                        break;
                    case '*':
                        nums.push(a*b);
                        break;
                    case '/':
                        nums.push(a/b);
                        break;
                }
                op.pop();

            }
            return nums.top();
        }
    }
};
