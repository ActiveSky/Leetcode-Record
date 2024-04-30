#
# @lc app=leetcode.cn id=438 lang=python3
# @lcpr version=30113
#
# [438] 找到字符串中所有字母异位词
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_len = len(p)
        p_sorted = sorted(p)
        res=[]
        i=0
        for i in range(len(s)-p_len+1):
            if sorted(s[i:i+p_len])==p_sorted:
                res.append(i)
        return res
                
        
# @lc code=end



#
# @lcpr case=start
# "cbaebabacd"\n"abc"\n
# @lcpr case=end

# @lcpr case=start
# "abab"\n"ab"\n
# @lcpr case=end

#

