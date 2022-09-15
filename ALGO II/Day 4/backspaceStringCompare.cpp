class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        for(int i = 0 ; i < s.size() ; i++){
            char c1 = s[i];
            
            if(c1 != '#')
                st1.push(c1);
            else if(! st1.empty()){
                st1.pop();
            }
        }
        
        for(int i = 0 ; i < t.size() ; i++){
            char c1 = t[i];
            
            if(c1 != '#')
                st2.push(c1);
            else if(! st2.empty()){
                st2.pop();
            }
        }
        
        string str1 = "" , str2 = "";
        while(! st1.empty()){
            str1 = st1.top() + str1;
            st1.pop();
        }
        
        while(! st2.empty()){
            str2 = st2.top() + str2;
            st2.pop();
        }
        
        if(str1 == str2)
            return true;
        else
            return false;
    }
};