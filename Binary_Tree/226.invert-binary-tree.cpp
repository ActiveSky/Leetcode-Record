/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30204
 *
 * [226] 翻转二叉树
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>

#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        // if (root == nullptr)
        //     return nullptr;

        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;

        // invertTree(root->left);
        // invertTree(root->right);

        // return root;

        invertTree2(root);
        return root;
    }
    TreeNode* invertTree2(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        // when q is not empy
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // swap left and right child
            swap(node->left, node->right);

            // push left and right child to queue
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
