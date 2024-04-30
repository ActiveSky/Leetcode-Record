/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=21913
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
 int removeDuplicates(vector<int>& nums) { 
    int slow = 0;
    for (int fast = 0;fast<nums.size();fast++){
        if(nums[fast]!=nums[slow]){
            slow++; // unique sequence to grow,first in index
            nums[slow] = nums[fast]; // second,assign the new unique value to unique sequence

        }
       
    }
     return slow+1;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

