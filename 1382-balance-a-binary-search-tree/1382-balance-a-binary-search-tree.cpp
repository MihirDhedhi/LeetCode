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
    
    void inorder(TreeNode* root, vector<int>& values) {
        
        if(root == NULL)
            return;
        
        inorder(root->left, values);
        
        values.push_back(root->val);
        
        inorder(root->right, values);
    }
    
    TreeNode* makeTree(vector<int>& values, int left, int right) {
        
        if(left > right)
            return NULL;
        
        int mid = (left + right) / 2;
        
        TreeNode* root = new TreeNode(values[mid]);
        
        root->left = makeTree(values, left, mid - 1);
        root->right = makeTree(values, mid + 1, right);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> values;
        
        inorder(root, values);
        
        return makeTree(values, 0, values.size() - 1);
    }
};