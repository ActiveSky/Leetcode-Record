/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 * @lcpr version=30204
 *
 * [1022] 从根到叶的二进制数之和
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr)
            return 0;
        preOrder(root, 0);
        return this->all_sum;
    }

   private:
    int all_sum = 0;
    void preOrder(TreeNode* root, int sum) {
        if (root == nullptr)
            return;
        sum = sum * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            all_sum += sum;
        }
        preOrder(root->left, sum);
        preOrder(root->right, sum);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,1,0,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
