class Solution {
public:
    string longestPalindrome(string s) {
       string s1=s;
       reverse(s1.begin(),s1.end());
       return lcs(s,s1,s.length(),s1.length());
    }

    string lcs(string X,string Y,int m,int n){
    string ans;
    int t[m+1][n+1];
    int res=0;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(X[i-1]==Y[j-1])
                t[i][j]=1 + t[i-1][j-1];
            else
                t[i][j]=0;
            
             if(t[i][j]>res) {
                        string temp=X.substr(i-t[i][j],t[i][j]);
                        string rev=temp;
                        reverse(rev.begin(),rev.end());
                        if(temp==rev){
                             ans=temp;
                             res=t[i][j];
                        }       
              }
        }
    }
        return ans;
 }
    
};