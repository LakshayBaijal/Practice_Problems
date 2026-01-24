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
    int countNodes(TreeNode* root) 
    {
        int total = 0;
        function(root,total);    
        return total;
    }

    void function(TreeNode* root,int &total)
    {
        if(root != NULL)
        {
            total ++;
        }
        if(root == NULL)
        {
            return;
        }

        function(root->left,total);
        function(root->right,total);
        return;
    }

    
};
