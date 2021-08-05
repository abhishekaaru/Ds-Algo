#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // constructor

    node(int val){
        data=val;
        next=NULL;
    }
}; 

// Insert Element

void InsertAtHead(node* &head,int val){

    node* n = new node(val);

    n->next = head;
    head = n;
}

void InsertAtTail(node* &head,int val){

    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }

    temp->next = n;
}

// Delete Element

void deleteAtHead(node* &head){

    node* todelete=head;
    head=head->next;

    delete todelete;

}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
    }

    node* temp=head;
    while(temp->next->data != val){
        temp=temp->next;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void deleteWithoutHeadptr(node* del)
    {
        if (del == NULL) {
           return;
        }
        
       else {
           
            if (del->next == NULL) {
             cout << "Can't delete last node without head" << endl;
              return;
            }
            
            struct node* temp = del->next;
            del->data = temp->data;
            del->next = temp->next;

            free(temp);
        }
    }

// Reverse Linked List

node* reverse(node* &head){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;

    }

    return prevptr;
}

// reverse in recursive way

node* reverseRecursive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node*newhead = reverseRecursive(head->next);
    head->next->next = head; // 2nd element point to head
    head->next = NULL;

    return newhead;
}

node* reverseKnode(node* &head,int k){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;

        count++;

    }

    if(nextptr != NULL){
        head->next = reverseKnode(nextptr,k);
    }

    return prevptr;
}

// Cycle

void makeACycle(node* &head,int pos){
    node* temp=head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){

        if(count == pos){
            startNode=temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
    
}

bool detectCycle(node* &head){

    node* slow=head;
    node* fast=head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    }

    return false;
}

void removeCycle(node* &head){

    node* slow=head;
    node* fast=head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast=head;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    
}

// Display Linked List

void display(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// Searching

bool search(node* head,int key){
    
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }

    return false;
}

int getMiddle(node *head)
{
   node* fastptr=head;
   node* slowptr=head;
   
    if(head!=NULL){
    
       while(fastptr!=NULL && fastptr->next!=NULL){
           fastptr = fastptr->next->next;
           slowptr = slowptr->next;
       }
       
    }
   
   return slowptr->data;
}

int main(){

    node* head=NULL;
    
    /* InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    display(head);

    InsertAtHead(head,0);
    InsertAtHead(head,4);
    display(head);

    deletion(head,2);
    display(head);

    deleteAtHead(head);
    display(head); */

    /* node* newhead = reverseRecursive(head);
    display(newhead);
 */
   /*  node* newhead1 = reverse(head);
    display(newhead1); */

    /* int k=2;
    node* newhead=reverseKnode(head,k);
    display(newhead); */

    /* cout<<search(head,0); */

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    makeACycle(head,3);
    cout<<detectCycle(head)<<endl;

    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);



    return 0;
} 