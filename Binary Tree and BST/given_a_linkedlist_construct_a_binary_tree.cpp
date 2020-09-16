//complete_binary_tree
void convertList2Binary(ListNode *head, BinaryTreeNode* &root) 
{ 
    // queue to store the parent nodes 
    queue<BinaryTreeNode *> q; 
  
    // Base Case 
    if (head == NULL) 
    { 
        root = NULL; // Note that root is passed by reference 
        return; 
    } 
  
    // 1.) The first node is always the root node, and add it to the queue 
    root = newBinaryTreeNode(head->data); 
    q.push(root); 
  
    // advance the pointer to the next node 
    head = head->next; 
  
    // until the end of linked list is reached, do the following steps 
    while (head) 
    { 
        // 2.a) take the parent node from the q and remove it from q 
        BinaryTreeNode* parent = q.front(); 
        q.pop(); 
  
        // 2.c) take next two nodes from the linked list. We will add 
        // them as children of the current parent node in step 2.b. Push them 
        // into the queue so that they will be parents to the future nodes 
        BinaryTreeNode *leftChild = NULL, *rightChild = NULL; 
        leftChild = newBinaryTreeNode(head->data); 
        q.push(leftChild); 
        head = head->next; 
        if (head) 
        { 
            rightChild = newBinaryTreeNode(head->data); 
            q.push(rightChild); 
            head = head->next; 
        } 
  
        // 2.b) assign the left and right children of parent 
        parent->left = leftChild; 
        parent->right = rightChild; 
    } 
} 