class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                myStack.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(myStack.empty())
                    return false;
                if(s[i]==')' && myStack.top()!='(')
                    return false;
                else if(s[i]=='}' && myStack.top()!='{')
                    return false;
                else if(s[i]==']' && myStack.top()!='[')
                    return false;
                myStack.pop();
            }
        }
        if(!myStack.empty())
            return false;
        return true;
    }
};