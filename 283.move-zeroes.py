#
# @lc app=leetcode.cn id=283 lang=python3
# @lcpr version=30113
#
# [283] 移动零
#


# @lcpr-template-start
from typing import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        for num in nums:
            if num!=0:
                nums[i]=num
                i+=1
        for j in range(i,len(nums)):
            nums[j]=0                
        


# @lc code=end


#
# @lcpr case=start
# [0,1,0,3,12]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#
