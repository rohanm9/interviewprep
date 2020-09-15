TreeNode* sortedarrtoBST(TreeNode* root,const vector<int> &A,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    root=new TreeNode(A[mid]);
    root->left=sortedarrtoBST(root->left,A,start,mid-1);
    root->right=sortedarrtoBST(root->right,A,mid+1,end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode* root=sortedarrtoBST(root,A,0,A.size()-1);
    return root;
}
