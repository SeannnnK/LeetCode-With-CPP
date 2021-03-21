/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
// bloomberg

// Definition for a binary tree node.

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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return abs(height(root->left) - height(root->right)) <= 1 &&
                isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }

    // bottom up
public:
    bool isBalanced2(TreeNode *root) {
        return height2(root) > 0;
    }
private:
    int height2(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = height2(root->left);
        int right =height2(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
};

int main()
{
    TreeNode root(3), left(9), right(20), left1(15), right1(17);
    root.left = &left;
    root.right = &right;
    right.left = &left1;
    right.right = &right1;
    Solution sol;
    cout << sol.isBalanced(&root) << endl;
    cout << sol.isBalanced2(&root) << endl;
    return 0;
}
// @lc code=end
