class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;
        if(s.size()%2 == 1)
            return false;
        if(s.size() == 0)
            return true;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stack_.push(s[i]);
            if(s[i]==')'){
                if(stack_.top() == '(')
                    stack_.pop();
                else
                    stack_.push(s[i]);
            }
            if(s[i]==']'){
                if(stack_.top() == '[')
                    stack_.pop();
                else
                    stack_.push(s[i]);
            }
            if(s[i]=='}'){
                if(stack_.top() == '{')
                    stack_.pop();
                else
                    stack_.push(s[i]);
            }
        }
        if(stack_.empty())
            return true;
        else 
            return false;
    }
};