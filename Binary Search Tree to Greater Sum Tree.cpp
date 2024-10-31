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
    int Sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        convertGreaterBST(root);
        return root;
    }
    void convertGreaterBST(TreeNode* Root)
    {
        if (Root == NULL)
        {
            return;
        }
        convertGreaterBST(Root->right);
        Sum += Root->val;
        Root->val = Sum;
        convertGreaterBST(Root->left);
    }
};