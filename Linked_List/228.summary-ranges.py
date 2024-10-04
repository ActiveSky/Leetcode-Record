#
# @lc app=leetcode.cn id=228 lang=python3
# @lcpr version=30122
#
# [228] 汇总区间
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []

        ranges = []
        start = nums[0]

        for i in range(1, len(nums)):
            # Check if the current number is not consecutive
            if nums[i] != nums[i - 1] + 1:
                # If we have a range, format it accordingly
                if start == nums[i - 1]:
                    ranges.append(str(start))
                else:
                    ranges.append(f"{start}->{nums[i - 1]}")
                # Update start to the current number
                start = nums[i]

        # Handle the last range or number
        if start == nums[-1]:
            ranges.append(str(start))
        else:
            ranges.append(f"{start}->{nums[-1]}")

        return ranges

        
# @lc code=end



#
# @lcpr case=start
# [0,1,2,4,5,7]\n
# @lcpr case=end

# @lcpr case=start
# [0,2,3,4,6,8,9]\n
# @lcpr case=end

#

