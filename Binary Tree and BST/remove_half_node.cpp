TreeNode* Solution::solve(TreeNode* A) {
    //we need to check this condition -_-
    if(A->left == NULL && A->right == NULL)return A;
    if(A->right == NULL)
        return solve(A->left);
    if(A->left == NULL)
        return solve(A->right);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
}