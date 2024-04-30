#
# @lc app=leetcode.cn id=128 lang=python3
# @lcpr version=30113
#
# [128] 最长连续序列
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums=set(nums)
        max_len=0
        for num in nums:
            if num-1 not in nums:
                cur_len=1
                while num+1 in nums:
                    num+=1
                    cur_len+=1
                max_len=max(max_len,cur_len)
        return max_len
# @lc code=end



#
# @lcpr case=start
# [100,4,200,1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,3,7,2,5,8,4,6,0,1]\n
# @lcpr case=end

#

