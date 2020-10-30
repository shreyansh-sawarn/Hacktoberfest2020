class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def dfs(x,y):
            if board[x][y] == 'X' or board[x][y] == 'A': 
                return
            else:
                board[x][y] = 'A'
                for nx, ny in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if 0 <= nx < M and 0 <= ny < N:
                        dfs(nx,ny)
                        
        if not board or not board[0]: 
            return
        
        M, N = len(board), len(board[0])
        
        for row in [0,M-1]:
            for col in range(N):
                if board[row][col] == 'O':
                    dfs(row,col)
        
        for col in [0,N-1]:
            for row in range(M):
                if board[row][col] == 'O':
                    dfs(row,col)
        for row in range(M):
            for col in range(N):
                if board[row][col] == 'O':
                    board[row][col] = 'X'
                elif board[row][col] == 'A':
                    board[row][col] = 'O'