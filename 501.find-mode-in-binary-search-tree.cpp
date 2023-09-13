/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=21913
 *
 * [501] 二叉搜索树中的众数
 */

#include <unordered_map>
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
    unordered_map<int, int> counts;
    vector<int> res;
    int count=0;
    int maxCount=1;
    TreeNode* pre;
    // vector<int> temp;

   public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }

    vector<int> help_traversal(TreeNode* root) {
        int maxCount = 1;

        traversal(root);

        for (auto& [val, nums] : counts) {
            if (nums > maxCount) {
                maxCount = nums;
                res.clear();
                res.push_back(val);
            } else if (nums == maxCount && maxCount > 1) {
                res.push_back(val);
            }
        }

        return res;
    };

    void traversal(TreeNode* root) {
        if (root == nullptr)
            return;

        counts[root->val]++;
        // insert the node when the whole tree has't the same elements;
        res.push_back(root->val);

        traversal(root->left);
        traversal(root->right);
    }

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);

        // code block
        if (pre == nullptr) {
            count = 1;
        } else if (root->val == pre->val) {
            count++;  // real number
        } else if (root->val != pre->val) {
            count = 1;  // restart the "count"
        }

        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        } else if (count == maxCount) {
            res.push_back(root->val);
        }
        pre = root;
        inorder(root->right);

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
