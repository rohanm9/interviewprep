void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            TreeLinkNode* t=q.front();
            q.pop();
            if(n==0) t->next=NULL;
            else t->next=q.front();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return;
}