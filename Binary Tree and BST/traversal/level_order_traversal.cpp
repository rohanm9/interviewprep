int height(TreeNode* root)
{
    if(root == NULL) return 0;

    return max(f(root->left), f(root->right))+1;
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<pair<int, TreeNode*>> q;
    int n = height(A);
    vector<vector<int>> ans(n);
    q.push({0, A});
    while(!q.empty())
    {
        pair<int, TreeNode*> curr = q.front();
        q.pop();
        ans[curr.first].push_back(curr.second->val);
        if(curr.second->left) q.push({curr.first+1, curr.second->left});
        if(curr.second->right) q.push({curr.first+1, curr.second->right});
    }
    for(int i=1;i<n;i+=2)
    {
        reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}



//using two stacks
void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty()) {

        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp) {

            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
