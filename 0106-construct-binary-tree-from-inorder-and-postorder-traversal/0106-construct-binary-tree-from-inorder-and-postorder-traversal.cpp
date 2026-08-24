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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() == 0)
            return NULL;
        
        int rootValue = postorder[postorder.size() - 1];
        
        TreeNode* root = new TreeNode(rootValue);
        
        int pos = 0;
        while(inorder[pos] != rootValue)
            pos++;
        
        vector<int> leftIn, rightIn;
        vector<int> leftPost, rightPost;
        
        for(int i = 0; i < pos; i++)
            leftIn.push_back(inorder[i]);
        
        for(int i = pos + 1; i < inorder.size(); i++)
            rightIn.push_back(inorder[i]);
        
        for(int i = 0; i < pos; i++)
            leftPost.push_back(postorder[i]);
        
        for(int i = pos; i < postorder.size() - 1; i++)
            rightPost.push_back(postorder[i]);
        
        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);
        
        return root;
    }
};