#include <iostream>
using namespace std;
// Node structure
struct Node{
    int data;
    Node* next;
};
// Linked List class
class LinkedList{
    private:
        Node* head;
    
    public:
        LinkedList(){
            head=nullptr;
        }
        // Function to insert a new node
        void insertNode(int value){
            Node* newNode= new Node();
            newNode->data=value;
            newNode->next=nullptr;

            if(head==nullptr){
                head=newNode;
            }else{
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newNode;
            }
            cout<<"Node with value "<<value<<" inserted."<< endl;
        }
        // Function to insert a new node at specific location
        void insertNodeAt(int value,int position){
                Node* newNode= new Node();
                newNode->data=value;
                if (position==1){
                    newNode->next=head;
                    head=newNode;
                    cout<<"Node with value "<<value<<" inserted at position "<<position<<"."<<endl;
                    return;
                }
                Node* temp=head;
                for(int i=1;temp!=nullptr && i<position-1;i++){
                    temp=temp->next;
                }
                if (temp==nullptr) {
                    cout<<"Position out of bounds."<<endl;
                    delete newNode;
                    return;
                }
                newNode->next=temp->next;
                temp->next=newNode;
                cout<<"Node with value "<<value<<" inserted at position "<< position <<"."<<endl;
            }
        // Function to delete a node
        void deleteNode(int value){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            if(head->data==value){
                Node* temp=head;
                head=head->next;
                delete temp;
                cout<<"Node with value "<<value<<" deleted."<<endl;
                return;
            }
            // Search for the node to delete
            Node* current=head;
            Node* prev=nullptr;
            while(current!=nullptr&&current->data!=value){
                prev=current;
                current=current->next;
            }
            if(current==nullptr){
                cout<<"Node with value "<<value<<" not found."<<endl;
                return;
            }
            prev->next=current->next;
            delete current;
            cout<<"Node with value "<<value<<" deleted."<<endl;
        }
        // Function to display the linked list
        void displayList(){
            if(head==nullptr){
                cout<<"List is empty."<<endl;
                return;
            }
            Node* temp=head;
            cout<<"Linked List: ";
            while(temp!=nullptr){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main() {
    LinkedList l;
    int op=-1,n,pos;
    do{
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
                    l.insertNodeAt(n, pos);
                    break;
            case 3:cout<<"Enter value to delete: ";
                    cin>>n;
                    l.deleteNode(n);
                    break;
            case 4:l.displayList();
                    break;
            case 0:break;
            default:cout<<"Enter Valid Operation Number: "<<endl;
        }
    }while(op!=0);
    return 0;
}