#
# @lc app=leetcode.cn id=118 lang=python3
# @lcpr version=30115
#
# [118] 杨辉三角
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows<=2:
            return [[1]*i for i in range(1,numRows+1)]
        # else numRows>=3
        res = [[1],[1,1]]
        for i in range(2,numRows):
            res.append([1]+[res[i-1][j]+res[i-1][j+1] for j in range(i-1)]+[1])
        
        return res 
# @lc code=end



#
# @lcpr case=start
# 5\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

