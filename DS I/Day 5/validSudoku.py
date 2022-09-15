class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        col_d = defaultdict(set)
        row_d = defaultdict(set)
        box_d = defaultdict(set)
        
        r, c = len(board), len(board[0])
        
        for i in range(r):
            for j in range(c):
                n = board[i][j]
                if n == ".":
                    continue
                if n in row_d[i]:
                    return False
                if n in col_d[j]:
                    return False
                box = j//3+(i//3*3)
                if n in box_d[box]:
                    return False
                
                row_d[i].add(n)
                col_d[j].add(n)
                box_d[box].add(n)
        return True