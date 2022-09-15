class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> CHAR(256,-1);
        int res=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            i=max(i,CHAR[s[j]]+1);
            res=max(res,j-i+1);
            CHAR[s[j]]=j;
        }
        return res;
    }
};