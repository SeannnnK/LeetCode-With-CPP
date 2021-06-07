/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
// amazon | apple | linkedin | microsoft

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy{0};
        ListNode* head = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1) {
            head->next = l1;
        } else {
            head->next = l2;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);
    node1.next = node2, node2.next = node3, node3.next = nullptr;

    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    node4.next = node5, node5.next = node6, node6.next = nullptr;

    Solution sol;
    ListNode* res = sol.mergeTwoLists(&node1, &node4);

    while (res) {
        cout << res->val << " ";
    }
    cout << endl;

    return 0;
}
// @lc code=end
