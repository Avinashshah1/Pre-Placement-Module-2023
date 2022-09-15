 bool solve(int i, int j, vector<vector<char>>& board, string word, string temp, int pos){
    if(pos >= word.length()){
        cout<<temp<<endl;
        return true;
    }
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[pos]){
        return false;
    }
    char a = board[i][j];
    board[i][j] = '*';
    temp+=a;        
    
    bool up = solve(i-1, j, board, word, temp, pos+1);
    bool right = solve(i, j+1, board, word, temp, pos+1);
    bool down = solve(i+1, j, board, word, temp, pos+1);
    bool left = solve(i, j-1, board, word, temp, pos+1);
    board[i][j] = a;
    if(up or right or down or left){
        return true;
    }
    return false;;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(board[i][j]==word[0]){
                if(solve(i, j, board, word, "", 0)){
                    return true;
                }
            }
        }
    }
    return false;
}