class BSTiterator{
    stack<TreeNode*> s;
public:
    //
    void pushAll(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    int next(){
        TreeNode* node=s.top();
        s.pop();
        pushAll(node->right);
        return node->val;
    }
    bool hasnext(){
        return !s.empty();
    }
    
};
class BSTreverseiterator{
    stack<TreeNode*> s;
public:
    void pushAll(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            root=root->right;
        }
    }
    int next(){
        TreeNode* node=s.top();
        s.pop();
        pushAll(node->left);
        return node->val;
    }
    bool hasnext(){
        return !s.empty();
    }
};
vector<int> Solution::recoverTree(TreeNode* A) {
    BSTiterator it;
    BSTreverseiterator revit;
    it.pushAll(A);
    revit.pushAll(A);
    vector<int> sol;
    int prev=INT_MIN,curr=it.next();
    while(prev<=curr&&it.hasnext()){
        prev=curr;
        curr=it.next();
    }
    sol.push_back(prev);
    prev=INT_MAX,curr=revit.next();
    while(prev>=curr&&revit.hasnext());
        prev=curr;
        curr=revit.next();
    }
    sol.push_back(prev);
    return sol;
}
