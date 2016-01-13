class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (tokens[i] == "-"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a - b);
            }
            else if (tokens[i] == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a / b);
            }
            else if (tokens[i] == "*"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a * b);
            }
            else{
                s.push(atoi(tokens[i].c_str()));
            }
        }
        if (s.empty()){
            return 0;
        }
        return s.top();
    }
};
