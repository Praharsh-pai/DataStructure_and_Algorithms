#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};
// Circular Doubly Linked List class
class CircularDoublyLinkedList{
    private:
        Node* head;

    public:
        CircularDoublyLinkedList(){
            head=nullptr;
        }
        // Function to insert a node
        void insertNode(int value) {
            Node* newNode= new Node();
            newNode->data=value;
            if(head==nullptr){
                head=newNode;
                newNode->next=head;
                newNode->prev=head;
            }else{
                Node* temp=head->prev;
                temp->next=newNode;
                newNode->prev=temp;
                newNode->next=head;
                head->prev=newNode;
            }
            cout<<"Node with value "<<value<<" inserted."<<endl;
        }
        // Function to delete a node
        void deleteNode(int value){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            if(head->data==value){
                if(head->next==head){
                    delete head;
                    head=nullptr;
                }else{
                    Node* last=head->prev;
                    last->next=head->next;
                    head->next->prev=last;
                    Node* toDelete=head;
                    head=head->next;
                    delete toDelete;
                }
                cout<<"Node with value "<<value<<" deleted."<<endl;
                return;
            }
            do{
                temp=temp->next;
            }while(temp!=head&&temp->data!=value);
            if(temp==head){
                cout<<"Node with value "<<value<<" not found."<<endl;
                return;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            cout<<"Node with value "<<value<<" deleted."<<endl;
        }
        // Function to display the list
        void display(){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            cout<<"List in forward direction: ";
            do{
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }while(temp!=head);
            cout<<"(head "<<head->data<<")"<< endl;
        }
};

int main() {
    CircularDoublyLinkedList l;  // Create a CircularDoublyLinkedList object
    int op=-1,n;
    do {
        cout<<"\nSelect an operation:\n";
        cout<<"1. Insert Node\n2. Delete Node\n3. Display List\n0. Exit\n";
        cin>>op;
        switch(op){
            case 1:cout<<"Enter value to insert: ";
                    cin>>n;
                    l.insertNode(n);
                    break;
            case 2:cout<<"Enter value to delete: ";
                    cin>>n;
                    l.deleteNode(n);
                    break;
            case 3:l.display();
                    break;
            case 0:break;
            default:
                cout<<"Enter Valid Operation Number: "<<endl;
        }
    }while(op!=0);
    return 0;
}