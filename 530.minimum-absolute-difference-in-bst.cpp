/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=21913
 *
 * [530] 二叉搜索树的最小绝对差
 */


#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    private:
    int ans = INT32_MAX;
    int pre = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        
        if(root==nullptr) return 0;
        
        getMinimumDifference(root->left);
        // code block

        if(pre!=-1)
            ans = min(ans,root->val-pre);
        pre = root->val;
        getMinimumDifference(root->right);
        return ans;

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

