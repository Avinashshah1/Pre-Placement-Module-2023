class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        queue<pair<int,int>> q;
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,-1,1};
        int one=0, ione = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 1)
                    one++;
            }
        }
        if(q.empty())
        {
            //cout << 1 << " ";
            if(grid[0][0] == 0 && one == 0) return 0;
            else return -1;
        }
        int ans = -1;
        // cout << ans;
        while(!q.empty())
        {
            ans++;
            //cout << ans << " ";
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx >= n || nxty >= m || nxtx < 0 || nxty < 0) continue;
                    if(grid[nxtx][nxty] == 0) continue;
                    q.push({nxtx,nxty});
                    ione++;
                    grid[nxtx][nxty] = 0;
                }
            }
        }
        if(ione != one) return -1;
        return ans;
    }
};