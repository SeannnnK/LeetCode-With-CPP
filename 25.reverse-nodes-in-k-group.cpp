/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// facebook | microsoft

#include <iostream>
#include <utility>
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) {
                return head;
            }
            node = node->next;
        }

        ListNode* new_node = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_node;
    }

private:
    // [first, last)
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        while (first != last) {
            ListNode* tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }
};

class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* pre = &dummy;

        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return dummy.next;
                }
            }
            ListNode* next = tail->next;
            tie(head, tail) = reverse(head, tail);
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }

        return dummy.next;
    }

private:
    // [first,last]
    pair<ListNode*, ListNode*> reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last->next;
        ListNode* p = first;
        while (prev != last) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {last, first};
    }
};

int main()
{
    vector<ListNode*> v(7, nullptr);
    ListNode* tmp;
    for (int i = 0; i < v.size(); ++i) {
        tmp = new ListNode(i + 1);
        v[i] = tmp;
    }
    for (int i = 0; i < v.size(); ++i) {
        v[i]->next = v[i + 1];
    }
    v[6]->next = nullptr;

    Solution1 so;
    ListNode* res = so.reverseKGroup(v[0], 3);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    for (int i = 0; i < v.size(); ++i) {
        delete (v[i]);
    }

    return 0;
}
// @lc code=end
