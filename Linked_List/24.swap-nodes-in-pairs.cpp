// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=21913
 *
 * [24] 两两交换链表中的节点
 */

#include <algorithm>
#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head) {
        // auto real_head=new ListNode(-1,head);

        if (head == nullptr || head->next == nullptr)
            return head;



        auto real_head = new ListNode(-1, head);
        auto fast = head->next;
        auto low = real_head;



        while (fast != nullptr && low->next != nullptr) {
            ListNode* next=fast->next;
           
            fast->next = low->next;
            low->next->next = next;
            low->next = fast;

            //renew the low
            low = low->next->next;
            // renew the fast
            if (next != nullptr)
                fast = next->next;
        }

        return real_head->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
