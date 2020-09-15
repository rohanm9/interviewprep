// inorder traversal
Node* kthSmallest(Node* root, int& k) 
{ 
    // base case 
    if (root == NULL) 
        return NULL; 
  
    // search in left subtree 
    Node* left = kthSmallest(root->left, k); 
  
    // if k'th smallest is found in left subtree, return it 
    if (left != NULL) 
        return left; 
  
    // if current element is k'th smallest, return it 
    k--; 
    if (k == 0) 
        return root; 
  
    // else search in right subtree 
    return kthSmallest(root->right, k); 
}