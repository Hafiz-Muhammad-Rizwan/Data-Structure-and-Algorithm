#include<iostream>
#include<queue>
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
    queue<TreeNode*>obj;
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
        {
            return root;
        }
        obj.push(root);
        while (obj.empty() == false)
        {
            TreeNode* Temp = obj.front();
            obj.pop();

            swap(Temp->left, Temp->right);

            if (Temp->left != NULL)
            {
                obj.push(Temp->left);
            }
            if (Temp->right != NULL)
            {
                obj.push(Temp->right);
            }
        }
        return root;
    }
};