/*
 * @lc app=leetcode.cn id=783 lang=cpp
 * @lcpr version=30204
 *
 * [783] 二叉搜索树节点最小距离
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
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
    int minDiffInBST(TreeNode* root) {
        if (root==nullptr) return 0;
        vector<int> nums;
        inorderTraversal(root, nums);
        int res = INT_MAX;
        for (int i=1;i<nums.size();i++) {
            res = min(res, nums[i]-nums[i-1]);
        }
        return res;
    }
    private:
    void inorderTraversal(TreeNode* root, vector<int>& nums) {
        if (root==nullptr) return;
        inorderTraversal(root->left, nums);
        //inorder traversal and add to nums
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */
