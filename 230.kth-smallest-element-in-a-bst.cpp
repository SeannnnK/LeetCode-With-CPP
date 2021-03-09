/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
// Definition for a binary tree node.
// bloomberg | google | uber
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    TreeNode root(3), left(1), right(4), last(2);
    root.left = &left;
    root.right = &right;
    left.right = &last;
    Solution sol;
    int res = sol.kthSmallest(&root, 1);
    cout << res << endl;
    return 0;
}