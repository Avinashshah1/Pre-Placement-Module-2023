class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0)
                    t[i][j]=INT_MAX-1;
                else if(i!=0 && j==0)
                    t[i][j]=0;
                else if(i==1 && j!=0)
                {
                    if(j%coins[0]==0)
                        t[i][j]=j/coins[0];
                    else
                        t[i][j]=INT_MAX-1;
                } 
            }     
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j)
                    t[i][j]= min(1 + t[i][j-coins[i-1]] , t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }
        }
        if(t[n][amount]==INT_MAX-1)
            return -1;
        return t[n][amount];
    }
};