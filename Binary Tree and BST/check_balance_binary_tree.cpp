int height(TreeNode* root,bool &flag){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left,flag);
    int r=height(root->right,flag);
    if(abs(l-r)>1){
        flag=false;
    }
    return max(l,r)+1;
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    bool flag=true;
    height(A,flag);
    return flag;
}
