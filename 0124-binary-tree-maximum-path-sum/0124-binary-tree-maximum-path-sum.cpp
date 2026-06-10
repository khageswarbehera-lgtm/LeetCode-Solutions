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
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        DFS(root,maxSum);
        return maxSum;
        
    }
    int DFS(TreeNode* root ,int &sum)
    {
        if(root==NULL)
        return 0;
        int left=max(0,DFS(root->left,sum));
        int right=max(0,DFS(root->right,sum));
        sum=max(sum,left+right+root->val);
        return max(left,right)+root->val;

    }
};