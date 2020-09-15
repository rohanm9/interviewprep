/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void sumnumbers(TreeNode *A,long long int sum,int &total,int m){
    if(A==NULL){
        return;
    }
    sum=(10*sum%m+A->val%m)%m;
    if(A->left==NULL&&A->right==NULL){
        total=(total%m+sum%m)%m;
    }
    sumnumbers(A->left,sum,total,m);
    sumnumbers(A->right,sum,total,m);
 }
int Solution::sumNumbers(TreeNode* A) {
    int total=0;
    int m=1003;
    sumnumbers(A,0,total,m);
    return total;
}
