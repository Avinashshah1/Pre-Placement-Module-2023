class Solution {
public:
    void recursive_fill (vector<vector<int>>& image, int sr, int sc, int color, int start_color) {
        if (color == start_color) return;
        if (sr < 0 || sr > image.size() - 1) return;
        if (sc < 0 || sc > image[0].size() - 1) return;
        if (image[sr][sc] != start_color) return;
        
        image[sr][sc] = color;     
        // One position up
        recursive_fill(image, sr - 1, sc, color, start_color);
        // One position down
        recursive_fill(image, sr + 1, sc, color, start_color);
        // One position left
        recursive_fill(image, sr, sc - 1, color, start_color);
        // One position right
        recursive_fill(image, sr, sc + 1, color, start_color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        recursive_fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};