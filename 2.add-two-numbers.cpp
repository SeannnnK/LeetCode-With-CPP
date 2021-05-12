/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
// adobe | airbnb | amazon | bloomberg | microsoft

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy{0};
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            val += carry;
            carry = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode l1(2), l1_2(4), l1_3(3);
    ListNode l2(2), l2_2(4), l2_3(3);
    l1.next = &l1_2, l1_2.next = &l1_3, l1_3.next = nullptr;
    l2.next = &l2_2, l2_2.next = &l2_3, l2_3.next = nullptr;
    Solution sol;
    ListNode* res = sol.addTwoNumbers(&l1, &l2);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
// @lc code=end
