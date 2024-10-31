#include<iostream>
#include<vector>
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
    vector<int>Sorted_Values;
    int Min_Diffrence = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        for (int i = 1; i < Sorted_Values.size(); i++)
        {
            if (Min_Diffrence > Sorted_Values[i] - Sorted_Values[i - 1])
            {
                Min_Diffrence = Sorted_Values[i] - Sorted_Values[i - 1];
            }
        }
        return Min_Diffrence;
    }
    void inOrderTraversal(TreeNode* Temp)
    {
        if (Temp == NULL)
        {
            return;
        }
        inOrderTraversal(Temp->left);
        Sorted_Values.push_back(Temp->val);
        inOrderTraversal(Temp->right);
    }
};