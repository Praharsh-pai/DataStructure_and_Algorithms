#include <iostream>
using namespace std;
// Node structure
struct Node{
    int data;
    Node* next;
};
// Circular Linked List class
class CircularLinkedList{
    private:
        Node* head;
    
    public:
        CircularLinkedList(){
            head=nullptr;
        }
        // Function to insert a node
        void insertNode(int value){
            Node* newNode= new Node();
            newNode->data=value;
            if(head==nullptr){
                head=newNode;
                newNode->next=head;
            }else{
                Node* temp=head;
                while(temp->next!=head){
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=head;
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
            Node* prev=nullptr;
            if(head->data==value) {
                if(head->next==head) {
                    delete head;
                    head=nullptr;
                }else{
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    temp->next=head->next;
                    delete head;
                    head=temp->next;
                }
                cout<<"Node with value "<<value<<" deleted."<<endl;
                return;
            }
            do{
                prev=temp;
                temp=temp->next;
            }while(temp!=head&&temp->data!=value);
            if(temp==head){
                cout<<"Node with value "<<value<<" not found."<< endl;
                return;
            }
            prev->next=temp->next;
            delete temp;
            cout<<"Node with value "<<value<<" deleted."<< endl;
        }
        // Function to display
        void displayList(){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            cout<<"Circular Linked List: ";
            do{
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }while(temp!=head);
            cout<<"(head "<<head->data<<")"<< endl;
        }
};
int main() {
    CircularLinkedList l;
    int op=-1,n;
    do{
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
            case 3:l.displayList();
                    break;
            case 0:break;
            default:
                cout<<"Enter Valid Operation Number: "<<endl;
        }
    }while(op!=0);
    return 0;
}
