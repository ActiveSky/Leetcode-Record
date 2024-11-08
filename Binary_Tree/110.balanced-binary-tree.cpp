/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    bool isBalanced(TreeNode* root) {
        int v = helper2(root);
        return v != -1;
    }

    bool helper(TreeNode* root) {
        if (root == nullptr)
            return true;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        int diff = abs(left_height - right_height);
        if (diff > 1)
            return false;

        return helper(root->left) && helper(root->right);
    }
    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    int helper2(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_height = helper2(root->left);
        // transmit the error code
        if (left_height == -1)
            return -1;
        int right_height = helper2(root->right);
        if (right_height == -1)
            return -1;
        // calculate the current height of the node
        int diff = abs(left_height - right_height);
        if (diff > 1)
            return -1;
        // return the height of the current node
        return max(left_height, right_height) + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
