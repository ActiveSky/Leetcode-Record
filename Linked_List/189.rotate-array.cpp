/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30113
 *
 * [189] 轮转数组
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        // 1.cacular the real k
        int n = nums.size();
        k = k % n;
        // 2.reverse the last k elements
        reverse(nums.end() - k, nums.end());
        // 3.reverse the first n-k elements
        reverse(nums.begin(), nums.end() - k);
        // 4.reverse the whole array
        reverse(nums.begin(), nums.end());

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
