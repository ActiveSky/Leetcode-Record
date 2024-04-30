#
# @lc app=leetcode.cn id=560 lang=python3
# @lcpr version=30113
#
# [560] 和为 K 的子数组
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        count = 0
        current_sum = 0
        prefix_sums = {0: 1}  # 初始化为0的累积和出现一次

        for num in nums:
            current_sum += num
            diff= current_sum - k
            if diff in prefix_sums:
                count += prefix_sums[diff]
            prefix_sums[current_sum] = prefix_sums.get(current_sum, 0) + 1

        return count
        
        
# @lc code=end



#
# @lcpr case=start
# [1,1,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n3\n
# @lcpr case=end

#

