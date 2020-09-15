/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildtree(TreeNode* root,vector<int>&A,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid,max=INT_MIN;
    for(int i=start;i<=end;i++){
        if(A[i]>max){
            max=A[i];
            mid=i;
        }
    }
    root= new TreeNode(max);
    root->left=buildtree(root->left,A,start,mid-1);
    root->right=buildtree(root->right,A,mid+1,end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode* root=buildtree(root,A,0,A.size()-1);
    return root;
}