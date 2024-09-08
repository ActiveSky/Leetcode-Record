/*
 * @lc app=leetcode.cn id=872 lang=cpp
 * @lcpr version=30204
 *
 * [872] 叶子相似的树
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> values1, values2;
        getLeafValues(root1, values1);
        getLeafValues(root2, values2);
        return values1 == values2;
    }

    private:
    void getLeafValues(TreeNode* root, vector<int>& values) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            values.push_back(root->val);
        }
        getLeafValues(root->left, values);
        getLeafValues(root->right, values);
    }
};
// @lc code=end

/*
// @lcpr case=start
//
[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,3,2]\n
// @lcpr case=end

 */
