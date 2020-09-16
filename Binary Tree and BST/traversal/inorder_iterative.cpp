/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    struct TreeNode* current=A;
    vector<int> soln;
    if(current==NULL){
        return soln;
    }
    while(!st.empty()||current!=NULL){
        while(current!=NULL){
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        soln.push_back(current->val);
        current=current->right;
    }
    return soln;
}
// vector<int>res;
// if(A==NULL)
// return res;
// stack<pair<TreeNode*,int>> s;
// s.push({A,0});
//
// while(!s.empty()){
//     pair<TreeNode*,int> p = s.top();
//     s.pop();
//     TreeNode *curr=p.first;
//     int state = p.second;
//     if(curr == NULL or state == 3)continue;
//     s.push({curr,state+1});
//     if(state == 0)
//         s.push({curr->left,0});
//     else if(state == 1)
//         res.push_back(curr->val);
//     else if(state == 2)
//         s.push({curr->right,0});
//
// }
// return res;






/////////////////////////////////////////////////////////////////
vector<int>res;
if(A==NULL)
return res;
stack<pair<TreeNode*,int>> s;
s.push({A,0});

while(!s.empty()){
    pair<TreeNode*,int> p = s.top();
    s.pop();
    TreeNode *curr=p.first;
    int state = p.second;
    if(curr == NULL or state == 3)continue;
    s.push({curr,state+1});
    if(state == 0)
        s.push({curr->left,0});
    else if(state == 1)
        res.push_back(curr->val);
    else if(state == 2)
        s.push({curr->right,0});

}
return res;
