/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void reverseOddLevelsHelper(TreeNode* left, TreeNode* right, int level) {
        if (!left || !right) return; // Base case: Stop when nodes are null

        // If the current level is odd, swap the values
        if (level % 2 == 1) {
            swap(left->val, right->val);
        }

        // Recurse for the next level
        reverseOddLevelsHelper(left->left, right->right, level + 1);
        reverseOddLevelsHelper(left->right, right->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr; // Edge case: Empty tree
        reverseOddLevelsHelper(root->left, root->right, 1); // Start recursion at level 1
        return root;
    }
};