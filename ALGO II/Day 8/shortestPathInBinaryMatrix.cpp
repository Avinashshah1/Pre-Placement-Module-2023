typedef vector<vector> v;
typedef queue <pair<int, int>> q_;

class Solution {
public:

int met = 0;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
    q_ q;
    q.push({0, 0});
    grid[0][0] = 1;
    array<int, 8> x = {-1, -1, 0, 1, 1, 1, 0, -1};
    array<int, 8> y = {0, 1, 1, 1, 0, -1, -1, -1};
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second; 
        if(i == m-1 && j == n-1) met = 1;
        for(int iter = 0; iter < 8; iter++){
            int x_ = i+x[iter];
            int y_ = j+y[iter];
            if(x_ < 0 || y_ < 0 || x_ >= m || y_ >= n || grid[x_][y_] > 0) continue;
            else if(grid[x_][y_] == 0 || grid[x_][y_] > grid[i][j] + 1){
                q.push({x_, y_}); 
                grid[x_][y_] = grid[i][j] + 1;
            } 
        }
        q.pop(); 
    }
    return met == 0 ? -1 : grid[m-1][n-1];
}
};