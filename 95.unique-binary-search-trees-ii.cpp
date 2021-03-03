/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
// Definition for a binary tree node.
#include <vector>
#include <iostream>

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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTree = helper(start , i - 1);
            vector<TreeNode*> rightTree = helper(i + 1, end);
            for (const auto& left : leftTree) {
                for (const auto& right : rightTree) {
                    TreeNode *root = new TreeNode(i);
                    root->left = clone(left);
                    root->right = clone(right);
                    result.push_back(root);
                }
            }
        }
        return result;
    }
private:
   TreeNode *clone(TreeNode *root)  {
       TreeNode *newRoot = nullptr;
       if (root) {
           newRoot = new TreeNode(root->val);
           newRoot->left = clone(root->left);
           newRoot->right= clone(root->right);
       }
       return newRoot;
   }
public:
   void traverse(TreeNode *root) {
       if (!root) {
           return;
       }
       cout << root->val << " ";
       traverse(root->left);
       traverse(root->right);
   }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<TreeNode*> res = sol.generateTrees(3);
    for (auto &node : res) {
        sol.traverse(node);
        cout << endl;
    }
    return 0;
}
// @lc code=end