/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ff first
#define ss second
#define pb push_back
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // going to contain <level,val of the node>
    vector<pair<int,int>> v;
    vector<int> tmp;
    queue<pair<TreeNode*,int>>q;
    q.push({A,0});
    while(!q.empty()){
        pair<TreeNode*,int> curr= q.front();
        v.pb({curr.ss,curr.ff->val});
        q.pop();
        if(curr.ff->left!=NULL)
            q.push({curr.ff->left,curr.ss+1});
        if(curr.ff->right!=NULL)
            q.push({curr.ff->right,curr.ss+1});
    }
    vector<vector<int>> soln(v.back().ff+1);
    for(auto &x:v){
        soln[x.ff].pb(x.ss);
    }
    return soln;
}
