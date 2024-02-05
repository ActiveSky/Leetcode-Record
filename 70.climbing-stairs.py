#
# @lc app=leetcode.cn id=70 lang=python3
# @lcpr version=30115
#
# [70] 爬楼梯
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<=2:
            return n
        #else others: condition that n>=3
        dp=[0]*(n+1)
        dp[1]=1
        dp[2]=2
        
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]            
        return dp[n]
# @lc code=end



#
# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#

