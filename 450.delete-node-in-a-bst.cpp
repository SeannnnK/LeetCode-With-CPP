/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
#include <iostream>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) {
                TreeNode *right = root->right;
                //delete root;
                return right;
            } else if (!root->right) {
                TreeNode *left = root->left;
                //delete root;
                return left;
            } else {
                TreeNode *successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};

int main()
{
    TreeNode root(5), left1(3), right1(6), left2(2), right2(4), last(7);
    root.left = &left1;
    root.right = &right1;
    left1.left = &left2;
    left1.right = &right2;
    right1.right = &last;
    Solution sol;
    TreeNode *res = sol.deleteNode(&root, 3);
    cout << res->val << endl;
    return 0;
}
// @lc code=end

