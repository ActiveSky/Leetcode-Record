#
# @lc app=leetcode.cn id=49 lang=python3
# @lcpr version=30113
#
# [49] 字母异位词分组
#


# @lcpr-template-start
# 导入类型声明的模块
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        words_dict = {}
        for word in strs:
            sorted_word="".join(sorted(word))
            if sorted_word in words_dict:
                words_dict[sorted_word].append(word)
            else:
                words_dict[sorted_word]=[word]
        result=list(words_dict.values())
        # sort by length and then by alphabetic order
        result.sort(key=lambda x:len(x))
        result=[sorted(x) for x in result]
        return result
# @lc code=end



#
# @lcpr case=start
# ["eat", "tea", "tan", "ate", "nat", "bat"]\n
# @lcpr case=end

# @lcpr case=start
# [""]\n
# @lcpr case=end

# @lcpr case=start
# ["a"]\n
# @lcpr case=end

#

