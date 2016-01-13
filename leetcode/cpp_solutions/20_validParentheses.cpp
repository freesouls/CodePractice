class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;  
        int i = 0;  
          
        while(i != s.length())  
        {  
            char c = s[i];  
            if (c != ')' && c != '}' && c != ']')  
            {  
                charStack.push(c);  
            }  
            else  
            { 
                if (charStack.size()==0)
                {
                    return false;
                }
                char pre = charStack.top();  
                switch(c)  
                {  
                case ')':  
                    if (pre == '(')  
                      charStack.pop();  
                    else   
                      return false;  
                    break;  
                        
                case '}':  
                    if (pre == '{')  
                      charStack.pop();  
                    else   
                      return false;  
                    break;  
                      
                case ']':  
                    if (pre == '[')  
                      charStack.pop();  
                    else   
                      return false;  
                    break;  
                }  
            }  
            ++i;  
        }  
        if (charStack.size() == 0)  
            return true;  
        else 
            return false;  
    } 
};