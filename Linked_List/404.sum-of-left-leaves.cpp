// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=21913
 *
 * [404] 左叶子之和
 */

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

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
   private:
    vector<int> res;

   public:
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root,0);
        int ans = accumulate(res.begin(), res.end(), 0);
        return ans;
    }

    void traversal(TreeNode* root,bool isLeft) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr && isLeft) {
            res.push_back(root->val);
        }
        // if (root->right != nullptr)
        traversal(root->left,1);
        traversal(root->right,0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
