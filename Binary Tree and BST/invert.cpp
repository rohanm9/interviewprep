void inverTree(TreeNode* A){
    if(A==NULL){
        return;
    }
    else{
        TreeNode* temp=A->left;
        A->left=A->right;
        A->right=temp;
    }
    inverTree(A->left);
    inverTree(A->right);
}
TreeNode* Solution::invertTree(TreeNode* A) {
    inverTree(A);
    return A;
}
