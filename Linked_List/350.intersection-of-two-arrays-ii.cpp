/*
 * @lc app=leetcode.cn id=350 lang=cpp
 * @lcpr version=30204
 *
 * [350] 两个数组的交集 II
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include<set>
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
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> temp(nums1);
        for (auto num : nums2){
            auto it = find(temp.begin(),temp.end(),num);
            if(it!=temp.end()){
                res.push_back(num);
                temp.erase(it);
        }
        }
        return res;

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */
