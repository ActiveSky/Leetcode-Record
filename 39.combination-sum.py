#
# @lc app=leetcode.cn id=39 lang=python3
# @lcpr version=30113
#
# [39] 组合总和
#


# @lcpr-template-start
from typing import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        def backtrack(start,target,path:List[int]):
            # 剪枝
            if target<0:
                return 
            if target==0:
                result.append(path[:])
                return
            for  i in range(start,len(candidates)):
                path.append(candidates[i])
                backtrack(i,target=target-candidates[i],path=path)
                path.pop()
        
        backtrack(0,target=target,path=[])
        return result
# @lc code=end



#
# @lcpr case=start
# [2,3,6,7]\n7\n
# @lcpr case=end

# @lcpr case=start
# [2,3,5]\n8\n
# @lcpr case=end

# @lcpr case=start
# [2]\n1\n
# @lcpr case=end

#

