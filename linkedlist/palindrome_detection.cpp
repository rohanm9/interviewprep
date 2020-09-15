 
  
bool isPalindrome(struct Node* head)  
{  
    struct Node *slow_ptr = head, *fast_ptr = head;  
    struct Node *second_half, *prev_of_slow_ptr = head;  
    struct Node* midnode = NULL; // To handle odd size list  
    bool res = true; // initialize result  
  
    if (head != NULL && head->next != NULL) {  
        /* Get the middle of the list. Move slow_ptr by 1  
        and fast_ptrr by 2, slow_ptr will have the middle  
        node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) {  
            fast_ptr = fast_ptr->next->next;  
  
            /*We need previous of the slow_ptr for  
            linked lists with odd elements */
            prev_of_slow_ptr = slow_ptr;  
            slow_ptr = slow_ptr->next;  
        }  
  
        /* fast_ptr would become NULL when there are even elements in list.  
        And not NULL for odd elements. We need to skip the middle node  
        for odd case and store it somewhere so that we can restore the  
        original list*/
        if (fast_ptr != NULL) {  
            midnode = slow_ptr;  
            slow_ptr = slow_ptr->next;  
        }  
  
        // Now reverse the second half and compare it with first half  
        second_half = slow_ptr;  
        prev_of_slow_ptr->next = NULL; // NULL terminate first half  
        reverse(&second_half); // Reverse the second half  
        res = compareLists(head, second_half); // compare  
  
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again  
  
        // If there was a mid node (odd size case) which  
        // was not part of either first half or second half.  
        if (midnode != NULL) {  
            prev_of_slow_ptr->next = midnode;  
            midnode->next = second_half;  
        }  
        else
            prev_of_slow_ptr->next = second_half;  
    }  
    return res;  
}  
  
/* Function to reverse the linked list Note that this  
    function may change the head */
void reverse(struct Node** head_ref)  
{  
    struct Node* prev = NULL;  
    struct Node* current = *head_ref;  
    struct Node* next;  
    while (current != NULL) {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
    }  
    *head_ref = prev;  
}  
