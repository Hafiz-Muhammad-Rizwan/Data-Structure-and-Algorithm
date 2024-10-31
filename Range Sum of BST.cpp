#include<iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL)
        {
            return 0;
        }
        if (root->val < low)
        {
            return rangeSumBST(root->right, low, high);
        }
        else if (root->val > high)
        {
            return rangeSumBST(root->left, low, high);
        }
        else
        {
            return root->val + (rangeSumBST(root->left, low, high) + (rangeSumBST(root->right, low, high)));
        }

    }
};