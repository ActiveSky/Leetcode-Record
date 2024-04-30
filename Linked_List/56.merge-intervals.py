#
# @lc app=leetcode.cn id=56 lang=python3
# @lcpr version=30122
#
# [56] 合并区间
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort(key=lambda x:x[0])
        res=[]
        pre_start, pre_end=intervals[0]
        for start, end in intervals[1:]:
            if start<=pre_end:
                left=min(pre_start, start)
                right=max(pre_end, end)
                pre_start, pre_end=left, right
            else:
                res.append([pre_start, pre_end])
                pre_start, pre_end=start, end
        res.append([pre_start, pre_end])
        return res
# @lc code=end



#
# @lcpr case=start
# [[1,3],[2,6],[8,10],[15,18]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,4],[4,5]]\n
# @lcpr case=end

#

