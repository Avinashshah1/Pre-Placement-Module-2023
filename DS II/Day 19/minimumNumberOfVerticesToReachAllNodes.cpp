vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    unordered_map<int, int> m;
    for(auto i:edges){
        m[i[1]]++;
    }
    for(int i=0; i<n; i++){
        if(m[i] == 0){
            ans.push_back(i);
        }
    }
    return ans;
}