vector<int> Solution::preorderTraversal(TreeNode* A) {
    TreeNode* current=A;
    vector<int> v;
    if(A==NULL){
        return v;
    }
    stack<TreeNode*> s;
    while(!s.empty()||current!=NULL){
        while(current!=NULL){
            v.push_back(current->val);
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        current=current->right;
    }
    return v;
}
