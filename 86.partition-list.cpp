/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }

        ListNode small(0);
        ListNode *smallHead = &small;
        ListNode large(0);
        ListNode *largeHead = &large;

        while (head) {
            if (head->val < x) {
                smallHead->next = head;
                smallHead = smallHead->next;
            } else {
                largeHead->next = head;
                largeHead = largeHead->next;
            }
            head = head->next;
        }

        largeHead->next = nullptr;
        smallHead->next = large.next;
        return small.next;
    }
};
// @lc code=end
