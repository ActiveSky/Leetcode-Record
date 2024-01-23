/*
 * @lc app=leetcode.cn id=229 lang=cpp
 * @lcpr version=30113
 *
 * [229] 多数元素 II
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
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;  // candidate element
        int count1 = 0, count2 = 0;          // candidate count
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {  // key code:when meet a new num,if it is not candidate1 or
                      // candidate2,then count1--,count2--
                count1--;
                count2--;
            }
        }
        // check if candidate1 and candidate2 are majority element
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
        vector<int> res;
        if (count1 > nums.size() / 3) {
            res.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            res.push_back(candidate2);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
