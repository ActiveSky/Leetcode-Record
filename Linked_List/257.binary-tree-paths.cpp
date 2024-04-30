// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=21913
 *
 * [257] 二叉树的所有路径
 */

#include <string>
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
    vector<vector<int>> res;

   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        vector<string> ans;

        for(auto &path:res){
            string s;
            for(auto &x:path)
                s.append(to_string(x) + "->");
            ans.push_back(s.substr(0, s.size() - 2));
        }
        return ans;
    }

   private:
    void dfs(TreeNode* root, vector<int> &path) {
        if (!root)
            return;
        path.push_back(root->val);
        // leaf Node
        if (!root->left && !root->right)
            res.push_back(path);

        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
