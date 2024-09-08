/*
 * @lc app=leetcode.cn id=563 lang=cpp
 * @lcpr version=30204
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        // 需要使用全局变量来记录当前节点的坡度
        // 构造新的函数
        if(root == nullptr) return 0;
        int tilt = 0;
        helper(root, tilt);
        return tilt;

    }
    private:
    int helper(TreeNode* root, int& tilt){
        if (root == nullptr) return 0;

        // 计算左子树的坡度
        int left_tilt = helper(root->left, tilt);
        // 计算右子树的坡度
        int right_tilt = helper(root->right, tilt);

        // 计算到当前节点的总坡度，全局变量累加
        tilt+= abs(left_tilt - right_tilt);

        // 返回当前节点的坡度
        return root->val + left_tilt + right_tilt;

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,9,3,5,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [21,7,14,1,1,2,2,3,3]\n
// @lcpr case=end

 */
