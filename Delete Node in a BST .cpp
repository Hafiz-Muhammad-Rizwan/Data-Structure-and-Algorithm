
#include<iostream>
using namespace std;

 class TreeNode {
 public:
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
        {
            return root;
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode* connect = root->right;
                delete root;
                root = NULL;
                return connect;
            }
            if (root->right == NULL)
            {
                TreeNode* connect = root->left;
                delete root;
                root = NULL;
                return connect;
            }
            TreeNode* connect = minValue(root->right);
            root->val = connect->val;
            root->right = deleteNode(root->right, connect->val);
        }
        return root;
    }
    TreeNode* minValue(TreeNode* Temp)
    {
        while (Temp->left != NULL)
        {
            Temp = Temp->left;
        }
        return Temp;
    }
};