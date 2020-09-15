int haspathsum(TreeNode* A,int sum){
    //backtrack
    if(A==NULL){
        return 0;
    }
    //founded
    if(sum==A->val&&A->left==NULL&&A->right==NULL){
        return 1;
    }
    //searching left and right using preorder traversal
    return haspathsum(A->left,sum-A->val)||haspathsum(A->right,sum-A->val);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    // dont forget to clean the memory after getting done
    return haspathsum(A,B);
}