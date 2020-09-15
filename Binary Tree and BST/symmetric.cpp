int isidentical(TreeNode* A,TreeNode* B){
    if(A==NULL&&B==NULL){
        return 1;
    }
    if(A==NULL||B==NULL){
        return 0;
    }
    return (A->val==B->val)&&isidentical(A->left,B->right)&&isidentical(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    else{
        return isidentical(A->left,A->right);   
    }
}
