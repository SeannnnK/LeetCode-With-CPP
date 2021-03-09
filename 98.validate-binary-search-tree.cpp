/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
// Definition for a binary tree node.
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        int last = 0xffffffff;
        stack<TreeNode*> s;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val < last) {
                return false;
            }
            last = root->val;
            root = root->right;
        }
        return true;
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
                level.push_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

int main()
{
    TreeNode root(2);
    TreeNode left(1);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;

    Solution sol;
    bool res = sol.isValidBST(&root);
    cout << res << endl;
    vector<vector<TreeNode*>> traverse = sol.levelOrder(&root);
    for (const auto& level : traverse) {
        for (const auto& node : level) {
            cout << node->val << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end

