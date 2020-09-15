vector <int> v2;
void sol(struct TreeNode* A,int B,vector<int> &v){
    if(A==NULL){
        return;
    }
    if(A->val==B){
        v.push_back(A->val);
        v2=v;
        return;
    }
    v.push_back(A->val);
    sol(A->left,B,v);
    sol(A->right,B,v);
    v.pop_back();
    
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> v;
    sol(A,B,v);
    return v2;
}