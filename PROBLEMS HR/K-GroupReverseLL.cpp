struct node *reverse (struct node *head, int k)
    { 
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *nextptr;
        
        int count = 0;
        
        while(curr != NULL && count < k){
            nextptr = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextptr;
            
            count++;
        }
        
        if(nextptr != NULL){
            head->next = reverse(nextptr,k);
        }
        
        return prev;
    }