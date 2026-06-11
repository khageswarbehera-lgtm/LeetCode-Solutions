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
TreeNode* getInOrderSuccessor(TreeNode* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;
        if(key<root->val)
        root->left=deleteNode(root->left,key);
        else if(key>root->val)
        root->right=deleteNode(root->right,key);
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
           else if(root->left==NULL || root->right==NULL)
           {
            return root->left==NULL ? root->right : root->left;
           }
           TreeNode* IS=getInOrderSuccessor(root->right);
           root->val=IS->val;
           root->right=deleteNode(root->right,IS->val);
           return root;
        }
        return root;
    }
};