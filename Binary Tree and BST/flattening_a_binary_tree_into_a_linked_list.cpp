void flattentree(TreeNode* curr,TreeNode* &temp){
    if(curr==NULL){
        return;
    }
    TreeNode* l=curr->left; curr->left=NULL;
    TreeNode* r=curr->right; curr->right=NULL;
    if(temp==NULL){
        // if it's the start of linkedlist
        temp=curr;
    }
    else{
        temp->right=curr;
        // moving temp to currently added node
        temp=temp->right;   
    }
    flattentree(l,temp);
    flattentree(r,temp);
}
TreeNode* Solution::flatten(TreeNode* A){
    TreeNode* temp=NULL;
    flattentree(A,temp);
    return A;
}