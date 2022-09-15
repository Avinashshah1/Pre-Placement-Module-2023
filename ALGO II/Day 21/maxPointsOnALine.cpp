class Pos2D{
public:
    int x;
    int y;
    Pos2D(){
        this->x = 0;
        this->y = 0;
    }
    Pos2D(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int triangle_area(Pos2D a, Pos2D b, Pos2D c)
{
	return (-b.y * c.x + a.y * (-b.x + c.x) + a.x * (b.y - c.y) + b.x * c.y);
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        if (n <= 2){
            return n;
        }
        vector<Pos2D> poses(n);
        for (int i = 0; i < n; i++){
            int x = points[i][0], y = points[i][1];
            poses[i] = Pos2D(x, y);
        }
        int best_number = 2;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int number = 2;
                for (int k = 0; k < n; k++){
                    if (k != i && k != j){
                        if (triangle_area(poses[i], poses[j], poses[k]) == 0){
                            number++;
                        }
                    }
                }
                best_number = max(best_number, number);
            }
        }
        return best_number;
    }
};