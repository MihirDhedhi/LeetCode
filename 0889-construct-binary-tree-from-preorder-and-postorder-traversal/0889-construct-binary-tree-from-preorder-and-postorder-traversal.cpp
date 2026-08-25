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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        if(preorder.size() == 1)
            return root;
        
        int leftRoot = preorder[1];
        
        int pos = 0;
        
        while(postorder[pos] != leftRoot)
            pos++;
        
        vector<int> leftPre;
        vector<int> rightPre;
        vector<int> leftPost;
        vector<int> rightPost;
        
        // Left subtree preorder
        for(int i = 1; i <= pos + 1; i++)
            leftPre.push_back(preorder[i]);
        
        // Right subtree preorder
        for(int i = pos + 2; i < preorder.size(); i++)
            rightPre.push_back(preorder[i]);
        
        // Left subtree postorder
        for(int i = 0; i <= pos; i++)
            leftPost.push_back(postorder[i]);
        
        // Right subtree postorder
        for(int i = pos + 1; i < postorder.size() - 1; i++)
            rightPost.push_back(postorder[i]);
        
        root->left = constructFromPrePost(leftPre, leftPost);
        root->right = constructFromPrePost(rightPre, rightPost);
        
        return root;
    }
};