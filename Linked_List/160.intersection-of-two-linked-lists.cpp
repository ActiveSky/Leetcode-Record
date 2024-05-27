/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30202
 *
 * [160] 相交链表
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
// @lcpr-template-end

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * @class Solution
 * @brief Class that provides a solution for finding the intersection node of two linked lists.
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Calculate the lengths of the two linked lists
        int lenA = 0, lenB = 0;
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA) {
            lenA++;
            nodeA = nodeA->next;
        }
        while (nodeB) {
            lenB++;
            nodeB = nodeB->next;
        }
        
        // Reset the pointers to the heads of the linked lists
        nodeA = headA;
        nodeB = headB;
        
        // Move the pointer of the longer list forward to make their lengths equal
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                nodeA = nodeA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                nodeB = nodeB->next;
            }
        }
        
        // Traverse both linked lists simultaneously until intersection is found
        while (nodeA && nodeB) {
            if (nodeA == nodeB) {
                return nodeA; // Intersection found
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        // If no intersection found, return nullptr
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
