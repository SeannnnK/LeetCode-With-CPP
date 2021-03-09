/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val)  {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
public:
    vector<vector<TreeNode*>> levelOrder(TreeNode *root) {
        vector<vector<TreeNode*>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                level.emplace_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
public:
    // interative
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        TreeNode *cur = root;
        TreeNode *newNode = new TreeNode(val);
        while (cur) {
            if (cur->val > val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = newNode;
                    break;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = newNode;
                    break;
                }
            }
        }
        return root ? root : newNode;
    }

};

int main()
{
    TreeNode root(4), left(2), right(7), left1(1), last(3);
    root.left = &left;
    root.right = &right;
    left.left = &left1;
    left.right = &last;
    Solution sol;
    TreeNode *node = sol.insertIntoBST(&root, 9);
    cout << node->val << endl;
    vector<vector<TreeNode*>> v = sol.levelOrder(node);
    for (const auto& level : v) {
        for (const auto& node : level) {
            cout << node->val << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end