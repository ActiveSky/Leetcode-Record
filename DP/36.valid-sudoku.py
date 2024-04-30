#
# @lc app=leetcode.cn id=36 lang=python3
# @lcpr version=30116
#
# [36] 有效的数独
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 1.check rows
        for row in board:
            if not self.isValidList(row):
                return False
        # 2.check columns
        for clo in range(9):
            column=[board[row][clo] for row in range(9)]
            if not self.isValidList(column):
                return False
        # 3.check 3*3
        for i in range(3):
            for j in range(3):
                block=[]
                for m in range(3):
                    for n in range(3):
                        block.append(board[i*3+m][j*3+n])
                if not self.isValidList(block):
                    return False
        return True
    def isValidList(self,lst):
        lst=[i for i in lst if i!="."]
        return len(lst)==len(set(lst))
    
            
# @lc code=end



#
# @lcpr case=start
# [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
# @lcpr case=end

# @lcpr case=start
# [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
# @lcpr case=end

#

