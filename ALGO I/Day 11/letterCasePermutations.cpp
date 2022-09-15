class Solution {
public:   
    void solve(string op,string ip,unordered_set<string> &s){
        if(ip.length()==0){
            s.insert(op);
            return;
        }
        string op1=op;
        string op2=op;
        if(isdigit(ip[0])){
            op1.push_back(ip[0]);
            op2.push_back(ip[0]);
        }
        else if(islower(ip[0])){
           op1.push_back(ip[0]-32);
           op2.push_back(ip[0]);
        }
        else if(isupper(ip[0])){
           op1.push_back(ip[0]+32);
           op2.push_back(ip[0]);
        }
        ip.erase(ip.begin()+0);
        solve(op1,ip,s);
        solve(op2,ip,s);
    }

    unordered_set<string> func(string &ip){
        string op="";
        unordered_set<string> s;
        solve(op,ip,s);
        return s;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        for(auto a:func(s))
            res.push_back(a);
        return res;
    }
    
};