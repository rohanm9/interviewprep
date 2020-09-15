//untested programs just to get an overview
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod = 1e9+7;
//In interviewbit they have used int val instead of ll data
struct BstNode{
    ll data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetNewNode(ll data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL
    return newNode;
}
// tree is a recursive data structure so Insert deletion searching traversals are going to be recursive
// bottom up solution
BstNode* Insert(BstNode* root,ll data){
    if(root == NULL){
        root = GetNewNode(data);
    }// just one way of constructing it...i could use less than too
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}
bool Search(BstNode* root,ll data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left,data);
    else return Search(root->right,data);
}
ll FindMin(BstNode* root){
    // while(root->left != NULL){
    //     root = root->left;
    // }
    // return root->data;
    if(root->left == NULL){
        return root->data;
    }
    return FindMin(root->left);
}
ll FindMax(BstNode* root){
    // while(root->left != NULL){
    //     root = root->left;
    // }
    // return root->data;
    if(root->right == NULL){
        return root->data;
    }
    return FindMax(root->right);
}
//Bottom up solution optimally choosing
ll height(BstNode* root){
    if(root == NULL) return -1;
    return max(height(root->left),height(root->right))+1;
}
//tree traversal dfs
void preorder(BstNode* root){
    if(root == NULL) return;
    print(root->data);
    preorder(root->left);
    preorder(root->right);
}
// inorder traversal of any BST is sorted
void inorder(BstNode* root){
    if(root == NULL) return;
    inorder(root->left);
    print(root->data);
    inorder(root->right);
}
void postorder(BstNode* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    print(root->data);
}
//tree traversal bfs no visit required
void bfs(BstNode* root){
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* curr = Q.front(); Q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL) Q.push(curr->left);
        if(curr->right != NULL) Q.push(curr->right);
    }
}
//Checking whether given tree is binary search or not ... I am going to write 2 solution
//It is neccessary to use
bool isBSTUtil(BstNode* root,BstNode* &prev){
    if(root == NULL) return true;
    if(!isBSTUtil(root->left,prev)) return false;
    if(prev != NULL && root->data <= prev->data) return false;
    prev = root;
    return isBSTUtil(root->right,prev);
}
bool isBSTUtil(BstNode* root,ll min,ll max){
        if(root==NULL) return true;
        if(root->data <= min && root->data >max and isBSTUtil(root->left,min,root->data) and isBSTUtil(root->right,root->data,max)){
            return true;
        }
        else{
            return false;
        }
}
// another way is using struct of {left_max,right_min,isleftBST,isrightBST}
bool isBST(BstNode* root){
    //return isBSTUtil(root,NULL);
    return isBSTUtil(root,NINF,INF);
}
//delete a node in Bst
Node* Delete(Node* root,int data){
    if(root==NULL){
        return root;
    }
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else{
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            ll data = FindMin(root->right);
            root->data = data;
            root->right = Delete(root->right,data);
        }
    }
}
//Find inorder Successor in a BST
Node* Getsuccessor(Node* root, int data){
    Node* current = Find(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL){
        return FindMin(current->right);
    }
    else{
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return ancestor;
    }

}
