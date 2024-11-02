/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30204
 *
 * [543] 二叉树的直径
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
   int max_diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) { 
        helper(root);
        return max_diameter;
     }
     int helper(TreeNode *root){
        if(root==nullptr) return 0;
        int left_height = helper(root->left);
        int right_height = helper(root->right);
        this->max_diameter = max(this->max_diameter, left_height+right_height);
        return max(left_height,right_height)+1;
     }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
