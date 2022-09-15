#include <bits/stdc++.h> 
vector<vector<int>> dp;

int dfs(int x, int y, int row, int col, vector<pair<int,int>>& directions)
{
    if (dp[x][y]!=-1) return dp[x][y];
    int ans=0;
    for(auto direction : directions)
    {
        int new_x = direction.first + x;
        int new_y = direction.second + y;
        if (new_x >=0 && new_x<row && new_y>=0 && new_y<col)
        {
                ans+=dfs(new_x, new_y, row, col, directions);
        }
    }
    
    dp[x][y] = ans;
    return ans;
}

int uniquePaths(int n, int m) {
    dp.clear();
    dp.resize(n, vector<int>(m, -1));
    vector<pair<int,int>> directions{make_pair(1,0),make_pair(0,1)};
    dp[n-1][m-1] = 1;
    return dfs(0,0,n,m,directions);
}