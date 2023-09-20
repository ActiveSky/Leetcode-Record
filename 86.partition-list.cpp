/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=21914
 *
 * [86] 分隔链表
 */

#include <iostream>
#include <vector>

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode * real_head=new ListNode(0,head);
        ListNode * slow=real_head;



        while (slow->next != nullptr) {
            if (slow->next->val < x) {
                slow = slow->next;
            }else break;
        }
        // all values < x
        if (slow->next == nullptr)
            return head;
        // Divide the list into two sublists.
        ListNode* fast = slow->next;
        slow->next = nullptr;
        ListNode* connect = fast;

        while (fast->next != nullptr) {
            if (fast->next->val >= x)
                fast = fast->next;
            else {
                slow->next = fast->next;
                slow= slow->next;
                fast->next = fast->next ->next;
               
            }
        }

        slow->next = connect;
        return real_head->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
