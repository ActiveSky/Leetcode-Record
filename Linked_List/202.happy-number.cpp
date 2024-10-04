/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include<set>
#include<string>
#include<cmath>
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
    bool isHappy(int n) {
        // check if happy num
        set<int> mySet;
        while (n!=1 && mySet.find(n)==mySet.end() ){
            mySet.insert(n);
            int sum = 0;
            string str_temp = to_string(n);
            for (auto a:str_temp){
                int temp_int = a-'0';
                temp_int *= temp_int;
                sum += temp_int;
            }
            n = sum;
        }
        return n == 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
