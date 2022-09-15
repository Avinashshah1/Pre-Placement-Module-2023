void dfs(int i, vector<vector<int>>& graph,  vector<int> temp, vector<vector<int>>& ans){
    if(i==graph.size()-1){
        ans.push_back(temp);
        return;
    }
    for(int j = 0;j<graph[i].size();j++){
        temp.push_back(graph[i][j]);
        dfs(graph[i][j], graph, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>>ans;
    vector<int>temp;
    temp.push_back(0);
    dfs(0, graph, temp, ans);
    return ans;
}