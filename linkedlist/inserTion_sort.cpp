ListNode* Solution::insertionSortList(ListNode* A) {
    if(A->next==NULL){
        return A;
    }
    ListNode *curr=A->next,*temp,*prev,*delta=A;
    while(curr!=NULL){
        temp=A; prev=NULL;
        while(temp!=curr){
            if(curr->val<temp->val){
                delta->next=curr->next;
                curr->next=temp;
                if(prev==NULL){
                    A=curr;
                }
                else{
                    prev->next=curr;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        delta=curr;
        curr=curr->next;
    }
    return A;
}