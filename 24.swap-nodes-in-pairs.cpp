/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
// bloomberg | microsoft | uber

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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while (curr->next && curr->next->next) {
            ListNode* nextOne = curr->next;
            ListNode* nextTwo = nextOne->next;
            ListNode* nextThree = nextTwo->next;
            curr->next = nextTwo;
            nextTwo->next = nextOne;
            nextOne->next = nextThree;
            curr = nextOne;
        }
        return dummy.next;
    }

public:
    // NOTE: this is the recursive version.
    ListNode* helper(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode* nextTwo = head->next;
        ListNode* nextThree = nextTwo->next;
        nextTwo->next = head;
        head->next = helper(nextThree);
        return nextTwo;
    }
};

int main()
{
    Solution sol;
    ListNode node1(1), node2(2), node3(3), node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    ListNode* head = &node1;
    ListNode* res = sol.swapPairs(head);
    res = sol.helper(res);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
// @lc code=end
