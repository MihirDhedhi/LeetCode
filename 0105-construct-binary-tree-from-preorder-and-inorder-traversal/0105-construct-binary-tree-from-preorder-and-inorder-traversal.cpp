/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int pos = 0;
        while(inorder[pos] != preorder[0])
            pos++;
        
        vector<int> leftPre, rightPre;
        vector<int> leftIn, rightIn;
        
        for(int i = 0; i < pos; i++)
            leftIn.push_back(inorder[i]);
        
        for(int i = pos + 1; i < inorder.size(); i++)
            rightIn.push_back(inorder[i]);
        
        for(int i = 1; i <= pos; i++)
            leftPre.push_back(preorder[i]);
        
        for(int i = pos + 1; i < preorder.size(); i++)
            rightPre.push_back(preorder[i]);
        
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        
        return root;
    }
};