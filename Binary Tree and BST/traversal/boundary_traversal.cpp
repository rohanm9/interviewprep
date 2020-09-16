void printLeaves(struct node* root) 
{ 
    if (root == NULL) 
        return; 
  
    printLeaves(root->left); 
  
    // Print it if it is a leaf node 
    if (!(root->left) && !(root->right)) 
        printf("%d ", root->data); 
  
    printLeaves(root->right); 
} 
  
// A function to print all left boundary nodes, except a leaf node. 
// Print the nodes in TOP DOWN manner 
void printBoundaryLeft(struct node* root) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->left) { 
  
        // to ensure top down order, print the node 
        // before calling itself for left subtree 
        printf("%d ", root->data); 
        printBoundaryLeft(root->left); 
    } 
    else if (root->right) { 
        printf("%d ", root->data); 
        printBoundaryLeft(root->right); 
    } 
    // do nothing if it is a leaf node, this way we avoid 
    // duplicates in output 
} 
  
// A function to print all right boundary nodes, except a leaf node 
// Print the nodes in BOTTOM UP manner 
void printBoundaryRight(struct node* root) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->right) { 
        // to ensure bottom up order, first call for right 
        // subtree, then print this node 
        printBoundaryRight(root->right); 
        printf("%d ", root->data); 
    } 
    else if (root->left) { 
        printBoundaryRight(root->left); 
        printf("%d ", root->data); 
    } 
    // do nothing if it is a leaf node, this way we avoid 
    // duplicates in output 
} 
  
// A function to do boundary traversal of a given binary tree 
void printBoundary(struct node* root) 
{ 
    if (root == NULL) 
        return; 
  
    printf("%d ", root->data); 
  
    // Print the left boundary in top-down manner. 
    printBoundaryLeft(root->left); 
  
    // Print all leaf nodes 
    printLeaves(root->left); 
    printLeaves(root->right); 
  
    // Print the right boundary in bottom-up manner 
    printBoundaryRight(root->right); 
} 