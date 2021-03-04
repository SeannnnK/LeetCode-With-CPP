/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
// Definition for singly-linked list.
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }
        ListNode *next1 = node->next;
        node->val = next1->val;
        node->next = next1->next;
        //delete(next1);
    }
};

int main()
{
    ListNode node1(1), node2(2), node3(3), node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    Solution sol;
    sol.deleteNode(&node3);
    ListNode *head = &node1;
    while (head) {
        cout << head->val <<  " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
// @lc code=end