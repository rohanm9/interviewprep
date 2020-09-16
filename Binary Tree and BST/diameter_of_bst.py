def height(node): 
      
    # Base Case : Tree is empty 
    if node is None: 
        return 0 ; 
      
    # If tree is not empty then height = 1 + max of left  
    # height and right heights  
    return 1 + max(height(node.left) ,height(node.right)) 
  
# Function to get the diamtere of a binary tree 
def diameter(root): 
      
    # Base Case when tree is empty  
    if root is None: 
        return 0; 
  
    # Get the height of left and right sub-trees 
    lheight = height(root.left) 
    rheight = height(root.right) 
  
    # Get the diameter of left and irgh sub-trees 
    ldiameter = diameter(root.left) 
    rdiameter = diameter(root.right) 
  
    # Return max of the following tree: 
    # 1) Diameter of left subtree 
    # 2) Diameter of right subtree 
    # 3) Height of left subtree + height of right subtree +1  
    return max(lheight + rheight + 1, max(ldiameter, rdiameter)) 
