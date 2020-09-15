#define ff first
#define ss second
map<int,vector<int>,greater<int>()> mp;

void dfs(TreeNode* root,int cnt){
    if(!root) return;
    mp[cnt].push_back(root->val);
    dfs(root->left,cnt-1);
    dfs(root->right,cnt);
}
vector<int> Solution::solve(TreeNode* A){
    mp.clear();
    vector<int> ans;
    if(!A) return {};
    dfs(A,0);
    for(auto i:mp)for(auto x:i.ss)ans.push_back(x);
    return ans;
}