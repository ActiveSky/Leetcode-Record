#
# @lc app=leetcode.cn id=152 lang=python3
# @lcpr version=30116
#
# [152] 乘积最大子数组
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        # 1. 状态定义
        maxdp = [0] * len(nums)
        mindp = [0] * len(nums)
        # 2. 初始化状态
        maxdp[0] = nums[0]
# @lc code=end



#
# @lcpr case=start
# [2,3,-2,4]\n
# @lcpr case=end

# @lcpr case=start
# [-2,0,-1]\n
# @lcpr case=end

#

