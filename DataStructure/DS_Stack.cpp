#include <iostream>
using namespace std;

#define MAX 100 
//creating a class to use the funtionalities of STACK
class Stack{
    int top;
    public: 
        int arr[MAX];//defining max size of STACK
        Stack() {top=-1;}
        bool push(int x);
        int pop();
        bool isEmpty();
};
//PUSH Operation
bool Stack::push(int x){
    if (top>=(MAX-1)){
        cout<<"Stack Overflow\n";
        return false;
    }else{
        arr[++top]=x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}
//POP Operation
int Stack::pop(){
    if (top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }else{
        int x=arr[top--];
        return x;
    }
}
//ISEMPTY Operation
bool Stack::isEmpty(){
    if (top<0){
        cout<<"Stack Empty\n";
        return true;
    }else{
        cout<<"Stack not Empty\n";
        return false;
    }
}
//Main functions
int main(){
    Stack s;
    int op=-1,n;
    while(op!=0){
        cout<<"Select an Operation"<<endl;
        cout<<"1. PUSH\n2. POP\n3. IS EMPTY\n0. END"<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<"Enter number to be pushed into Stack"<<endl;
                    cin>>n; 
                    s.push(n);
                    break;
            case 2: cout<<s.pop()<<endl;
                    break;
            case 3: s.isEmpty();
                    break;
            case 0: break;
            default: cout<<"Enter Valid Operation Number: "<<endl;
        }
    }
    return 0;
}