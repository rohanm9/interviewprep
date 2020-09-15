ListNode* Solution::detectCycle(ListNode* A) {
    if(A==NULL){
        return NULL;
    }
    if(A->next==NULL){
        return NULL;
    }
    ListNode *slow=A;
    ListNode *fast=A;
    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow==NULL||fast==NULL||fast->next==NULL){
        return NULL;
    }
    fast=A;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}