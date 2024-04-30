// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=21913
 *
 * [19] 删除链表的倒数第 N 个结点
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto real_head = new ListNode(0, head);
        auto fast = real_head;
        auto low = real_head;
        n++;
        while (n--) {
            fast = fast->next;
        }
        while (fast != nullptr){
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;
        return real_head->next;
        
        
    }


    /**
     * SB linked list,BIG BIG BIG SB
     * just for 'SB',why you make the first element pointed by the head?
    */
    ListNode* SB_solution(ListNode* head, int n) {
        // two points
        auto fast = head;
        auto low = head;
        // n++;
        while (n-- ){
            fast = fast->next;        
        }
            

        while (fast!=nullptr && fast->next != nullptr) {
            fast = fast->next;
            low = low->next;
        }
       
        
        if(low==head && fast==nullptr ) 
            return head->next;

        if (low->next != nullptr)
            low->next = low->next->next;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
