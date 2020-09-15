//defining iterator like a sort array 

//minimum to maximum iterator
class BSTiterator{
    stack<TreeNode*> s;
    public:
        void pushAll(TreeNode* root){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
        }
        int next(){
            TreeNode* node=s.top();
            pushAll(node->right);
            return node->val;
        }
        bool hasnext(){
            return !s.empty();
        }
};
//maximum to minimum iterator
class BSTreiterator{
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
            pushAll(node->left);
            return node->val;
        }
        bool hasnext(){
            return !s.empty();
        }
            
};
int Solution::t2Sum(TreeNode* A, int B) {
    BSTiterator it;
    BSTreiterator reit;
    it.pushAll(A);
    reit.pushAll(A);
    int a=it.next();
    int b=reit.next();
    int sum=B;
    while(it.hasnext()&&reit.hasnext()&&a!=b){
            cout<<a<<" "<<b<<endl;
            if(a+b==sum){
                return 1;
            }
            else if(a+b>sum){
                b=reit.next();
            }
            else{
                a=it.next();
            }
    }
    return 0;
}
