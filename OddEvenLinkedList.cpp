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

void display(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// K-Append

int length(node* head){

    int l=0;
    node* temp=head;
    while(temp != NULL){
        l++;
        temp=temp->next;
    }

    return l;
}

node* evenAfterOdd(node* &head){

    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next != NULL && even->next != NULL){

        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }

}

int main(){

    node* head=NULL;
    int a[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        InsertAtTail(head,a[i]);
    }
    display(head);

    evenAfterOdd(head);
    display(head);

    return 0;
}