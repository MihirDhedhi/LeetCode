/*
 // Definition for a QuadTree node.
 class Node {
 public:
     bool val;
     bool isLeaf;
     Node* topLeft;
     Node* topRight;
     Node* bottomLeft;
     Node* bottomRight;

     Node() {
         val = false;
         isLeaf = false;
         topLeft = NULL;
         topRight = NULL;
         bottomLeft = NULL;
         bottomRight = NULL;
     }

     Node(bool _val, bool _isLeaf) {
         val = _val;
         isLeaf = _isLeaf;
         topLeft = NULL;
         topRight = NULL;
         bottomLeft = NULL;
         bottomRight = NULL;
     }

     Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
          Node* _bottomLeft, Node* _bottomRight) {
         val = _val;
         isLeaf = _isLeaf;
         topLeft = _topLeft;
         topRight = _topRight;
         bottomLeft = _bottomLeft;
         bottomRight = _bottomRight;
     }
 };
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        
        if(quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val || quadTree2->val, true);
        }
        
        if(quadTree1->isLeaf) {
            if(quadTree1->val)
                return new Node(true, true);
            else
                return quadTree2;
        }
        
        if(quadTree2->isLeaf) {
            if(quadTree2->val)
                return new Node(true, true);
            else
                return quadTree1;
        }
        
        Node* root = new Node(false, false);
        
        root->topLeft = intersect(quadTree1->topLeft,
                                  quadTree2->topLeft);
        
        root->topRight = intersect(quadTree1->topRight,
                                   quadTree2->topRight);
        
        root->bottomLeft = intersect(quadTree1->bottomLeft,
                                     quadTree2->bottomLeft);
        
        root->bottomRight = intersect(quadTree1->bottomRight,
                                      quadTree2->bottomRight);
        
        // Check if all four children are same leaf
        if(root->topLeft->isLeaf &&
           root->topRight->isLeaf &&
           root->bottomLeft->isLeaf &&
           root->bottomRight->isLeaf &&
           
           root->topLeft->val == root->topRight->val &&
           root->topLeft->val == root->bottomLeft->val &&
           root->topLeft->val == root->bottomRight->val) {
            
            return new Node(root->topLeft->val, true);
        }
        
        return root;
    }
};