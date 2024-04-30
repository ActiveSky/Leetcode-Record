/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=21917
 *
 * [92] 反转链表 II
 */

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* real_head = new ListNode(0, head);
        ListNode* slow = real_head;
        // make the left pointed to the left node of the "left" position
        auto k=left;
        k--;
        while (k-- && slow->next) {
            slow = slow->next;
        }

        auto slow_head = slow;
        slow = slow->next;
        ListNode* fast = slow->next;
        // check out whether the length of list lower than "left"
        if (fast == nullptr)
            return head;

        cout << fast->val << " " << slow->val << endl;


        while (fast && right > left) {
            ListNode* temp = fast->next;

            fast->next = slow_head->next;
            slow_head->next = fast;
           
            fast = temp;
            right--;
            // cout << "value:"<<right << endl;
        }

        slow->next = fast;

        return real_head->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
