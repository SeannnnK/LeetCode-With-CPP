/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
// Unknown

#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* start = head;
        int len = 0;
        while (start) {
            ++len;
            start = start->next;
        }

        int to_delete_location = len - n;
        int i = 0;
        start = &dummy;
        while (i < to_delete_location) {
            start = start->next;
            ++i;
        }

        // ListNode* tmp = start->next;
        start->next = start->next->next;
        // delete(tmp);

        return dummy.next;
    }
};

// one pass with the two pointer slow and fast pointer
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* slow = &dummy, *fast = &dummy;
        
        for (int i = 1; i <= n + 1; ++i) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};

int main()
{
    vector<ListNode*> v(5, nullptr);
    for (int i = 0; i < 5; ++i) {
        v[i] = new ListNode(i + 1);
    }
    for (int i = 1; i < 4; ++i) {
        v[i - 1]->next = v[i];
    }
    v[4]->next = nullptr;

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(v[0], 2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
// @lc code=end
