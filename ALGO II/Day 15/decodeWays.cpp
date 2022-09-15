class Solution {
public:
    int isValid(char a,char b)
    {
        if(a=='0')
            return -1;
        else if(a=='1')
            return 1;
        else if(a=='2')
            if(b>='0' and b<='6')
                return 1;
        return 0; 
    }
    int numDecodings(string s) 
    {
        if(s.size()==1)
        {
            if(s[0]=='0')
                return 0;
            else
                return 1;
        }
        int n = s.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        if(s[n-1]!='0')
            dp[n-1]=1;
        if(isValid(s[n-2],s[n-1])==1)
            dp[n-2] = 1 + dp[n-1];
        else if(isValid(s[n-2],s[n-1])==0)
            dp[n-2] = dp[n-1];
        else
            dp[n-2] = 0;
        for(int i=n-3;i>=0;i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            else
                dp[i]+=dp[i+1];
            
            if(isValid(s[i],s[i+1]))
                dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};