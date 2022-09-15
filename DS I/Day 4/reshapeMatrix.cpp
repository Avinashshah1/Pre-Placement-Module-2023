class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size()){
            r=mat.size();
            c=mat[0].size();
        }
        vector<int> temp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                temp.push_back(mat[i][j]);
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<r;i++){
            vector<int> p;
            for(int j=0;j<c;j++){
                p.push_back(0);
            }
            res.push_back(p);
        }
        int x=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=temp[x];
                x++;
            }
        }
        return res;
    }
};