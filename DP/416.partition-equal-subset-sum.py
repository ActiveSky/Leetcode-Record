#
# @lc app=leetcode.cn id=416 lang=python3
# @lcpr version=30116
#
# [416] 分割等和子集
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        total_sum=sum(nums)
        if total_sum%2!=0:
            return False
        target=total_sum//2
        
        # 1.定义dp数组,dp[i][j]表示前i个数中是否存在和为j的子集
        dp=[[False]*(target+1) for _ in range(len(nums)+1)]
        for i in range(len(nums)+1):
            dp[i][0]=True
        for i in range(1, len(nums) + 1):
            for j in range(1, target + 1):
                if nums[i - 1] > j:
                    dp[i][j] = dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]]
        return dp[len(nums)][target]
# @lc code=end



#
# @lcpr case=start
# [1,5,11,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,5]\n
# @lcpr case=end

#

