//not solvable using preorder
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
   map<int,vector<int>> m;
   vector<vector<int>> soln;
   TreeNode* current=A; int x;
   queue<pair<TreeNode*,int>> q;
   pair<TreeNode*,int> p;
   q.push(make_pair(A,0));
   while(!q.empty()){
            p=q.front(); current=p.first; x=p.second; m[x].push_back(current->val);
       if(current->left!=NULL){
            q.push(make_pair(current->left,x-1));
       }
       if(current->right!=NULL){
            q.push(make_pair(current->right,x+1));
       }
       q.pop();
   }
   for(auto it=m.begin();it!=m.end();it++){
       soln.push_back(it->second);
   }
   return soln;
}
