#include <iostream>
using namespace std;

#define MAX 100 
//creating a class to use the funtionalities of QUEUE
class Queue{
    int front, rear, size;
    int arr[MAX]; // Maximum size of the queue
    public:
        Queue() {
            front = rear = -1;
            size = 0;
        }
        bool enqueue(int x);
        int dequeue();
        bool isEmpty();
        bool isFull();
};
//Enqueue Function
bool Queue::enqueue(int x){
    if (isFull()){
        cout<<"Queue Overflow\n";
        return false;
    }else{
        if (front==-1)
            front=0;
        rear=(rear+1)%MAX;
        arr[rear]=x;
        size++;
        cout << x << " enqueued into the queue\n";
        return true;
    }
}
// Dequeue Function
int Queue::dequeue(){
    if (isEmpty()){
        cout<<"Queue Underflow\n";
        return 0;
    }else{
        int x=arr[front];
        front=(front+1)%MAX;
        size--;
        return x;
    }
}
// Check if queue is empty
bool Queue::isEmpty(){
    return (size==0);
}
// Check if queue is full
bool Queue::isFull(){
    return (size==MAX);
}
//Main functions
int main(){
    Queue q;
    int op=-1,n;
    while(op!=0){
        cout<<"Select an Operation"<<endl;
        cout<<"1. Enqueue\n2. Dequeue\n3. IsFULL??\n4. IsEmpty??\n0. END"<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<"Enter number to be Queued"<<endl;
                    cin>>n; 
                    q.enqueue(n);
                    break;
            case 2: cout<<q.dequeue()<<endl;
                    break;
            case 3: if(q.isFull())
                        cout<<"Queue is Full"<<endl;
                    else    
                        cout<<"Queue is not Full"<<endl;
                    break;
            case 4: if(q.isEmpty())
                        cout<<"Queue is Empty"<<endl;
                    else    
                        cout<<"Queue is not Empty"<<endl;
                    break;
            case 0: break;
            default: cout<<"Enter Valid Operation Number: "<<endl;
        }
    }
    return 0;
}