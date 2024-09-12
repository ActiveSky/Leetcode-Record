/*
 * @lc app=leetcode.cn id=993 lang=cpp
 * @lcpr version=30204
 *
 * [993] 二叉树的堂兄弟节点
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <queue>
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr)
            return false;
        // use queue to traverse the tree layer by layer
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int xh = -1, yh = -1;  // x and y's index in the current layer
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    if (node->left->val == x)
                        xh = i;
                    if (node->left->val == y)
                        yh = i;
                }
                if (node->right) {
                    q.push(node->right);
                    if (node->right->val == x)
                        xh = i;
                    if (node->right->val == y)
                        yh = i;
                }
            }
            if (xh != -1 && yh != -1 && xh != yh) return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4,null,5]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4]\n2\n3\n
// @lcpr case=end

 */
