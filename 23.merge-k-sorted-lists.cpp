/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
// airbnb | amazon | facebook | google | linkedin | microsoft | twitter | uber
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare {
    bool operator() (ListNode *node1, ListNode* node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        ListNode dummy(0);
        ListNode *node = &dummy;
        for (const auto& list : lists) {
            q.push(list);
        }
        while (!q.empty()) {
            node->next = q.top();
            q.pop();
            node = node->next;
            if (node->next) {
                q.push(node->next);
            }
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(5);

    ListNode *n4 = new ListNode(1);
    ListNode *n5 = new ListNode(3);
    ListNode *n6 = new ListNode(4);

    ListNode *n7 = new ListNode(2);
    ListNode *n8 = new ListNode(6);

    n1->next = n2, n2->next = n3, n3->next = nullptr;
    n4->next = n5, n5->next = n6, n6->next = nullptr;
    n7->next = n8, n8->next = nullptr;

    vector<ListNode*> lists{n1, n4, n7};
    Solution sol;
    ListNode *res = sol.mergeKLists(lists);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
// @lc code=end