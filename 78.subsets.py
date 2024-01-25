#
# @lc app=leetcode.cn id=78 lang=python3
# @lcpr version=30113
#
# [78] 子集
#


# @lcpr-template-start
from typing import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start, subset: List[int]):
            # 将当前subset添加到结果集中，空集也要
            result.append(subset[:])

            # 遍历从start开始的nums元素，依次加入subset中
            for i in range(start, len(nums)):
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()

        result = []
        backtrack(0, [])
        return result


# @lc code=end


#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#
