#
# @lc app=leetcode.cn id=53 lang=python3
# @lcpr version=30113
#
# [53] 最大子数组和
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        current_max=global_max=nums[0]
        for i in range(1,len(nums)):
            current_max=max(nums[i],current_max+nums[i])
            global_max=max(global_max,current_max)
        return global_max
# @lc code=end



#
# @lcpr case=start
# [-2,1,-3,4,-1,2,1,-5,4]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

# @lcpr case=start
# [5,4,-1,7,8]\n
# @lcpr case=end

#

