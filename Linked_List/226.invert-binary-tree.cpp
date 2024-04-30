/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=21913
 *
 * [226] 翻转二叉树
 */

#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

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
    TreeNode* invertTree(TreeNode* root) { return post_order(root); }

   private:
    TreeNode* level_traversal(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        // the queue to help store nodes
        queue<TreeNode*> q;
        // initialize the queue
        q.push(root);

        while (!q.empty()) {
            // store the size of the queue temporarily
            for (int i = q.size(); i > 0; i--) {
                auto curr = q.front();
                q.pop();
                // swap the left and right nodes
                swap(curr->left, curr->right);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        // return the root
        return root;
    }

    TreeNode* post_order(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        // this is "pre_order template"
        swap(root->left, root->right);


        // test 
        // result: exit BUG,no instance of this type of function which have such arugments:TreeNode *
        // dont't know it clearly

        // swap(post_order(root->left), post_order(root->right));
        post_order(root->left);
        post_order(root->right);

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
