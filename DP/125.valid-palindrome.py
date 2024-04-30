#
# @lc app=leetcode.cn id=125 lang=python3
# @lcpr version=30116
#
# [125] 验证回文串
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        filtered_s="".join(i.lower() for i in s if i.isalnum())
        return filtered_s==filtered_s[::-1]
    
# @lc code=end



#
# @lcpr case=start
# "A man, a plan, a canal: Panama"\n
# @lcpr case=end

# @lcpr case=start
# "race a car"\n
# @lcpr case=end

# @lcpr case=start
# " "\n
# @lcpr case=end

#

