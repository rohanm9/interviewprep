int Solution::minDepth(TreeNode* A) {
    if(A->left==NULL&&A->right==NULL){
        return 1;
    }
    else if(A->left==NULL)
            return minDepth(A->right)+1;
    else if(A->right==NULL)
            return minDepth(A->left)+1;
    else{
        int l=minDepth(A->left);
        int r=minDepth(A->right);
        return min(l,r)+1;   
    }
}
