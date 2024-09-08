/*
 * @lc app=leetcode.cn id=897 lang=cpp
 * @lcpr version=30204
 *
 * [897] 递增顺序搜索树
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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return buildOnlyRightTree(res);
    }

   private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    TreeNode* buildOnlyRightTree(vector<int>& res) {
        if (res.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(res[0]);
        res.erase(res.begin());
        root->right = buildOnlyRightTree(res);
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,8,1,null,null,null,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,7]\n
// @lcpr case=end

 */
