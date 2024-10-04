#
# @lc app=leetcode.cn id=120 lang=python3
# @lcpr version=30116
#
# [120] 三角形最小路径和
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # If the triangle is empty, return 0
        if not triangle:
            return 0
        
        # Start from the second to last row and move upwards
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                # Update the current cell with the minimum path sum
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1])
        
        # The top element now contains the minimum path sum
        return triangle[0][0]

        
        
# @lc code=end



#
# @lcpr case=start
# [[2],[3,4],[6,5,7],[4,1,8,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[-10]]\n
# @lcpr case=end