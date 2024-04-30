#
# @lc app=leetcode.cn id=322 lang=python3
# @lcpr version=30116
#
# [322] 零钱兑换
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 1.dp list to store the minimum number of coins needed to make up the amount
        dp = [float("inf")] * (amount + 1)
        # 2.0 amount needs 0 coins
        dp[0] = 0
        # 3.iterate from 1 to amount
        for i in range(1,amount+1):
            # 4.interate through each coin
            for coin in coins:
                # 5.if the current coin is less than or equal to i and the number of coins used is less
                if coin<=i:
                    dp[i]=min(dp[i],dp[i-coin]+1)
        
        # 6.if dp[amount] is still the initial value, it means that the total amount cannot be made up
        if dp[amount]==float("inf"):
            return -1
        else:
            return dp[amount]
# @lc code=end



#
# @lcpr case=start
# [1, 2, 5]\n11\n
# @lcpr case=end

# @lcpr case=start
# [2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#

