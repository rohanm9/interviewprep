/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* A,ListNode* B){
    if(A==NULL&&B==NULL){
        return NULL;
    }
    ListNode* head=NULL,*temp;
    while(A!=NULL&&B!=NULL){
        if(A->val<=B->val){
            if(head==NULL){
                head=A;
                temp=A;
            }
            else{
                temp->next=A;
                temp=A;
            }
            A=A->next;
        }
        else{
            if(head==NULL){
                head=B;
                temp=B;
            }
            else{
                temp->next=B;
                temp=B;
            }
            B=B->next;
        }
    }
    if(A!=NULL){
        temp->next=A;
    }
    if(B!=NULL){
        temp->next=B;
    }
    return head;
}
void mergesort(ListNode *&A){
    if(A->next==NULL){
        return;
    }
    ListNode *slow=A,*fast=A->next;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *B=slow->next;
    slow->next=NULL;
    mergesort(A);
    mergesort(B);
    A=merge(A,B);
}
ListNode* Solution::sortList(ListNode* A) {
    mergesort(A);
    return A;
}
