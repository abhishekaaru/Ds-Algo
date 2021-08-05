#include<bits/stdc++.h>
using namespace std;

#define n 20

class Queue{
    int* a;
    int front;
    int back;
    
    public:
    Queue(){
        a = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x){

        if(back == n-1){
            cout<<"Queue is overflow"<<endl;
        }

        back++;
        a[back] = x;
        
        if(front == -1){
            front++;
        }
    }

    void dequeue(){

        if(front == -1 || front>back){
            cout<<"There is no items to pop out"<<endl;
        }

        front++;
    }

    int peek(){
        
        if(front == -1 || front>back){
            cout<<"There is no items to peek"<<endl;
        }

        return a[front];
    }

    bool empty(){
        
        if(front == -1 || front>back){
            return true;
        }

        return false;
    }

};

int main(){

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.peek()<<endl;

    q.dequeue();
    cout<<q.peek()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;

    return 0;

}
