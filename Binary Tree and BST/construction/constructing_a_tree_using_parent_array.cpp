void createNode(int parent[], int i, Node *created[], Node **root) 
{ 
    // If this node is already created 
    if (created[i] != NULL) 
        return; 
  
    // Create a new node and set created[i] 
    created[i] = newNode(i); 
  
    // If 'i' is root, change root pointer and return 
    if (parent[i] == -1) 
    { 
        *root = created[i]; 
        return; 
    } 
  
    // If parent is not created, then create parent first 
    if (created[parent[i]] == NULL) 
        createNode(parent, parent[i], created, root); 
  
    // Find parent pointer 
    Node *p = created[parent[i]]; 
  
    // If this is first child of parent 
    if (p->left == NULL) 
        p->left = created[i]; 
    else // If second child 
        p->right = created[i]; 
} 
  
// Creates tree from parent[0..n-1] and returns root of the created tree 
Node *createTree(int parent[], int n) 
{ 
    // Create an array created[] to keep track 
    // of created nodes, initialize all entries 
    // as NULL 
    Node *created[n]; 
    for (int i=0; i<n; i++) 
        created[i] = NULL; 
  
    Node *root = NULL; 
    for (int i=0; i<n; i++) 
        createNode(parent, i, created, &root); 
  
    return root; 
} 