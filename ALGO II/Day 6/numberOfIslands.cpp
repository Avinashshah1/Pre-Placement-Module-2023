class Solution {
public:
    int count, sizex, sizey;
    bool visited[500][500];
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    
    int numIslands(vector<vector<char>>& grid) {
        sizex = grid.size();
        sizey = grid[0].size();
        
        for (int i = 0; i < sizex; i++) {
            for (int j = 0; j < sizey; j++) {
                if (grid[i][j] == '1') {
                    recursion(grid, i, j);
                    count += 1;
                }
            }
        }
        
        return count;
    }
    
    int check(vector<vector<char>>& grid, int x, int y) {
        if (x > -1 && y > -1 && x < sizex && y < sizey) {
            if (grid[x][y] == '0') {
                return 0;
            } 
            
            return 1;
        }
        
        return 0;
    }

    void recursion (vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        int newx, newy;
        
        for (int i = 0; i < 4; i++) {
            newx = x + dirx[i];
            newy = y + diry[i];
            
            if (check((vector<vector<char>>&) grid, newx, newy) == 1) {
                recursion(grid, newx, newy);
            }
        }
        
        return;
    }
};