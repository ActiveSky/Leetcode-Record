/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30204
 *
 * [222] 完全二叉树的节点个数
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
//    计算完全二叉树的节点总数
    int countNodes(TreeNode* root) {
        
        // 递归退出的条件
        if(root==NULL)
            return 0;

        int leftDepth = 0, rightDepth = 0;
        TreeNode *leftNode = root, *rightNode = root;
        // 计算左子树和右子树的深度
        // 计算左子树的深度
        while(leftNode!=NULL){
            leftNode = leftNode->left;
            leftDepth++;
        }
        // 计算右子树的深度
        while(rightNode!=NULL){
            rightNode=rightNode->right;
            rightDepth++;
        }
        // 如果左右子树的深度相同，说明是满二叉树
        if(leftDepth==rightDepth){
            // 等价于2^leftDepth-1
            return (1 << leftDepth) - 1; //位运算,左移运算
        }
        // 如果左右子树的深度不同，说明不是满二叉树
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
