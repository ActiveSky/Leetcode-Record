#
# @lc app=leetcode.cn id=239 lang=python3
# @lcpr version=30113
#
# [239] 滑动窗口最大值
#


# @lcpr-template-start
from collections import deque
from typing import *

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if nums == [] or k == 0:
            return []
        deq=deque()
        res=[]
        for i in range(len(nums)):
            # beyond the window and remove
            if deq and deq[0]<=i-k:
                deq.popleft()
            while deq and nums[i]>nums[deq[-1]]:
                deq.pop()
            deq.append(i)
            if i>=k-1:
                res.append(nums[deq[0]])
        return res
            
            
        
# @lc code=end



#
# @lcpr case=start
# [1,3,-1,-3,5,3,6,7]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

#

