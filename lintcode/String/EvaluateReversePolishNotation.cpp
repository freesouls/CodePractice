class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            int flag = 0;
            if (tokens[i] == "+") {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a+b);
            }
            else if (tokens[i] == "-") {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a-b);
            }
            else if (tokens[i] == "*") {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a*b);
            }
            else if (tokens[i] == "/") {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a/b);
            }
            else {
                nums.push(atoi(tokens[i].c_str()));
            }

        }

        return nums.top();
    }
};
