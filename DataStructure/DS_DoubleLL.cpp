#include <iostream>
using namespace std;
// Node structure
struct Node{
    int data;
    Node* prev;
    Node* next;
};
// Doubly Linked List class
class DoublyLinkedList{
    private:
        Node* head;
    
    public:
        DoublyLinkedList() {
            head=nullptr;
        }
        // Function to insert a node
        void insertNode(int value){
            Node* newNode= new Node();
            newNode->data=value;
            newNode->prev=nullptr;
            newNode->next=nullptr;

            if(head==nullptr){
                head=newNode;
            }else{
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->prev=temp;
            }
            cout<<"Node with value "<<value<<" inserted."<< endl;
        }
        // Function to insert a new node at specific location
        void insertNodeAtPosition(int value,int position){
            Node* newNode= new Node();
            newNode->data=value;
            newNode->prev=nullptr;
            newNode->next=nullptr;
            if(position==1){
                newNode->next=head;
                if(head!=nullptr){
                    head->prev=newNode;
                }
                head=newNode;
            }else{
                Node* temp=head;
                for(int i=1;i<position-1 && temp!=nullptr;i++){
                    temp=temp->next;
                }
                if(temp==nullptr){
                    cout<<"Position out of bounds. Node not inserted."<<endl;
                    delete newNode;
                    return;
                }
                newNode->next=temp->next;
                if(temp->next!=nullptr){
                    temp->next->prev=newNode;
                }
                temp->next=newNode;
                newNode->prev=temp;
            }
            cout<<"Node with value "<<value<<" inserted at position "<<position<<"."<<endl;
        }
        // Function to delete a node
        void deleteNode(int value){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            while(temp!=nullptr&&temp->data!=value){
                temp=temp->next;
            }
            if(temp==nullptr){
                cout<<"Node with value "<<value<<" not found."<<endl;
                return;
            }
            if(temp==head){
                head=head->next;
                if(head!=nullptr)
                    head->prev=nullptr;
            }else if(temp->next==nullptr){
                temp->prev->next=nullptr;
            }else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            delete temp;
            cout<<"Node with value "<<value<<" deleted."<<endl;
        }
        // Function to display
        void display(){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            while(temp!=nullptr){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL"<< endl;
        }
};
int main() {
    DoublyLinkedList l;
    int op=-1,n,pos;

    do {
        cout<<"\nSelect an operation:\n";
        cout<<"1. Insert Node\n2. Insert At Specific Location\n3. Delete Node\n4. Display List\n0. Exit\n";
        cin>>op;
        switch(op){
            case 1:cout<<"Enter value to insert: ";
                    cin>>n;
                    l.insertNode(n);
                    break;
            case 2:cout << "Enter value to insert: ";
                    cin >> n;
                    cout << "Enter position to insert at: ";
                    cin >> pos;
                    l.insertNodeAtPosition(n, pos);
                    break;
            case 3:cout<<"Enter value to delete: ";
                    cin>>n;
                    l.deleteNode(n);
                    break;
            case 4:l.display();
                    break;
            case 0:break;
            default:
                cout<<"Enter Valid Operation Number: "<<endl;
        }
    }while(op!=0);
    return 0;
}