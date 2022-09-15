class Solution {
public:
    vector<string>ans;
    void lecs(string &digits,int i,string m,unordered_map<int,string>&up){
        if (i>=digits.size()){ans.push_back(m);return;}
        for(int j=0;j<up[digits[i]-'0'].length();j++){
            char add=up[digits[i]-'0'][j];
            lecs(digits,i+1,m+add,up);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>up;
        up[2]="abc";up[3]="def";up[4]="ghi";up[5]="jkl";up[6]="mno";up[7]="pqrs";
        up[8]="tuv";up[9]="wxyz";
        string m="";
        if (digits.size()>=1)lecs(digits,0,m,up);
        return ans;
    }
};