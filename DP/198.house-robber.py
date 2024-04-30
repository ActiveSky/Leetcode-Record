#
# @lc app=leetcode.cn id=198 lang=python3
# @lcpr version=30115
#
# [198] 打家劫舍
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        # check if nums is empty
        if not nums:
            return 0
        n=len(nums)
        if n==1:
            return nums[0]
        
        dp=[0]*(n)
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])
        
        for i in range(2,n):
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        return dp[n-1]
# @lc code=end



#
# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [2,7,9,3,1]\n
# @lcpr case=end

#

