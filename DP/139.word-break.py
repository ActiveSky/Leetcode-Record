# @lcpr-before-debug-begin
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=139 lang=python3
# @lcpr version=30116
#
# [139] 单词拆分
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 1.dp list to store whether the substring from 0 to i can be broken into words
        dp = [False] * (len(s) + 1)
        # 2.0 length string can be broken into words
        dp[0] = True
        # 3.iterate from 1 to length of string
        for i in range(1, len(s) + 1):
            # 4.iterate through each word in the word dictionary
            for word in wordDict:
                # 5.if the current word is less than or equal to i and the substring from i-len(word) to i is in the word dictionary
                if len(word) <= i and dp[i - len(word)] and s[i - len(word):i] == word:
                    dp[i] = True
                    
        return dp[len(s)]
# @lc code=end



#
# @lcpr case=start
# "leetcode"\n["leet", "code"]\n
# @lcpr case=end

# @lcpr case=start
# "applepenapple"\n["apple", "pen"]\n
# @lcpr case=end

# @lcpr case=start
# "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
# @lcpr case=end

#

