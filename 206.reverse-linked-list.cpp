/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
// adobe | amazon | apple | bloomberg | facebook | microsoft | snapchat | twitter | uber | yahoo |
// yelp | zenefits

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) {
            return head;
        }

        ListNode* prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            /* keep the next */
            next = cur->next; 
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    node1.next = &node2, node2.next = &node3, node3.next = &node4, node4.next = &node5;
    node5.next = &node6, node6.next = nullptr;
    Solution sol;
    ListNode* res = sol.reverseList(&node1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
// @lc code=end
