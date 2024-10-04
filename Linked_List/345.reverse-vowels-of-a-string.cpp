/*
 * @lc app=leetcode.cn id=345 lang=cpp
 * @lcpr version=30204
 *
 * [345] 反转字符串中的元音字母
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
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
    string reverseVowels(string s) {
        string strs = "aeiouAEIOU";
        int left = 0, right = s.length() - 1;
        while(left<right){
            while(left<right && strs.find(s[left])==string::npos)
                left++;
            while(left<right && strs.find(s[right])==string::npos)
                right--;
            if(left<right){
                swap(s[left], s[right]);
                left++, right--;
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "IceCreAm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */
