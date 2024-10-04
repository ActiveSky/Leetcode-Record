/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
// @lcpr-template-end
// @lc code=start
class Solution {
   public:
    void reverseString(vector<char>& s) { 
        int left = 0, right = s.size()-1;
        while (left<right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        };
    };
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

