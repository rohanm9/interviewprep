TTreeNode* treeBuilder(TreeNode* root,vector<int> &A,vector<int> &B,int si,int ei,int sp,int ep){
    if(si>ei||sp>ep){
        return NULL;
    }
    int r=B[ep];
    root=new TreeNode(r);
    int mid;
    for(int i=si;i<=ei;i++){
        if(A[i]==r){
            mid=i;
            break;
        }
    }
    root->left=treeBuilder(root->left,A,B,si,mid-1,sp,sp+mid-si-1);
    root->right=treeBuilder(root->right,A,B,mid+1,ei,sp+mid-si,ep-1);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    TreeNode* root=treeBuilder(root,A,B,0,A.size()-1,0,B.size()-1);
    return root;
}
