/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        return helper(headA, headB);
    }

    ListNode* helper(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        if (headA == headB) return headA;

        //calculate the length of the two list
        int lenA = 0, lenB = 0;
        ListNode* pA = headA, *pB = headB;
        while (pA) {
            ++lenA;
            pA = pA->next;
        }
        while (pB) {
            ++lenB;
            pB = pB->next;
        }

        // move it initial position
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                pA = pA->next;
            }
        }else {
            for (int i = 0; i < lenB - lenA; ++i) {
                pB = pB->next;
            }
        }
        while (pA && pB) {
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
