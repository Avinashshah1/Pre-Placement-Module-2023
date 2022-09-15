class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.length()-lcs(word1,word2,word1.length(),word2.length()) + word2.length()-lcs(word1,word2,word1.length(),word2.length());
    }
    int lcs(string X,string Y,int m,int n){
    int t[m+1][n+1];
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
              t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }  
    return t[m][n];
}
};